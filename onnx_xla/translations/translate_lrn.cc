#include "onnx_xla/operator_registry.h"

namespace onnx_xla {
// Translat LRN
// 1. Square input
// 2. Use reduce to sum
onnxStatus translateLRN(const Node& n,
                                      XlaBuilder& builder,
                                      ValueOpMap& valueToOp) {
  auto dataType = onnxToPrimitive(n.inputs().at(0)->elemType());
  // Read in attributes and make them XlaOp
  // TODO: Refactor this conversion
  float alpha = 1e-4f;
  if (n.hasAttribute(kalpha)) {
    alpha = n.f(kalpha);
  }
  auto alphaOp = ::tensorflow::FloatLiteral(&builder, dataType, alpha);

  float beta = 0.75f;
  if (n.hasAttribute(kbeta)) {
    beta = n.f(kbeta);
  }
  auto betaOp = ::tensorflow::FloatLiteral(&builder, dataType, beta);

  float bias = 1.0f;
  if (n.hasAttribute(Symbol("bias"))) {
    beta = n.f(kbeta);
  }
  auto biasOp = ::tensorflow::FloatLiteral(&builder, dataType, bias);

  if (!n.hasAttribute(ksize)) {  // TODO: Enforce
    std::cerr << "Missing required size attribute" << std::endl;
    return ONNXIFI_STATUS_INVALID_MODEL;
  }
  auto size = n.i(ksize);
  auto sizeOp = ::tensorflow::FloatLiteral(&builder, dataType, size);

  // Square input
  auto inputOp = valueToOp.at(n.inputs().at(0));
  auto squaredOp = builder.Mul(inputOp, inputOp);

  // Pool with add, making the required attributes
  // Note: kSame pads 1 more in the higher values of a dimension when the
  // padding
  // required is odd (which corresponds to ONNX LRN operator definition)
  // TODO: Use OperatoryRegistry function from Softmax PR
  XlaComputation add;
  {
    XlaBuilder builder("add");
    auto y = builder.Parameter(0, ShapeUtil::MakeShape(dataType, {}), "y");
    auto x = builder.Parameter(1, ShapeUtil::MakeShape(dataType, {}), "x");
    builder.Add(y, x);
    add = builder.Build().ConsumeValueOrDie();
  }

  std::vector<int64> windowDimensions(n.inputs().at(0)->sizes().size(), 1);
  windowDimensions.at(1) = size;
  std::vector<int64> windowStrides(windowDimensions.size(), 1);

  auto sumSquaresOp = builder.ReduceWindow(
      squaredOp, builder.ConstantLiteral(Literal::Zero(dataType)), add,
      windowDimensions, windowStrides, Padding::kSame);

  // Do final arithmetic
  valueToOp[n.outputs().at(0)] = builder.Div(
      inputOp,
      builder.Pow(builder.Add(biasOp, builder.Mul(alphaOp, sumSquaresOp)),
                  betaOp));
  return ONNXIFI_STATUS_SUCCESS;
}
REGISTER_OPERATOR_TRANSLATOR(LRN, translateLRN)
}