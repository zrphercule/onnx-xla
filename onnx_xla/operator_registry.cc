#include "onnx_xla/operator_registry.h"
#include <iostream>
namespace onnx_xla  {
  
  OperatorRegistry::OperatorRegisterOnce::OperatorRegisterOnce(const Symbol& nodeKind, TranslationFunction translator)  {
    auto& map = OperatorRegistry::map();
    if (!map.insert(std::pair<Symbol, TranslationFunction>(nodeKind, translator)).second)  {
      throw std::runtime_error("Registry error: Operator added more than once");
    }
  }

  onnxStatus OperatorRegistry::translate(const Node& n, XlaBuilder& builder, ValueOpMap& valueToOp, const ValueLiteralMap& valueToLiteral)  {
    auto& map = OperatorRegistry::map();
    auto it = map.find(n.kind());
    if (it != map.end()) {
      return it->second(n, builder, valueToOp, valueToLiteral);
    } else {
      return ONNXIFI_STATUS_UNSUPPORTED_OPERATOR;
    }
  }

  OperatorRegistry& OperatorRegistry::registry()  {
    static OperatorRegistry registry_;
    return registry_;
  }

  TranslationMap& OperatorRegistry::map()  {
    static TranslationMap map;
    return map;
  }


  //TODO: ENFORCE_EQ
  //Test this
  //Takes in data tensor and shape input
  //Error if shape input is dynamic
  //Parses ONNX shape input (can have 0's and one -1)
  //Produces new_sizes attribute to make XlaOp for Reshape
  onnxStatus translateReshape(const Node& n, XlaBuilder& builder, ValueOpMap& valueToOp, const ValueLiteralMap& valueToLiteral)  {
    //Check if shape input is static
    auto shapeDataIt = valueToLiteral.find(n.inputs().at(1));
    if (shapeDataIt == valueToLiteral.end())  {  // TODO: ENFORCE_EQ
      std::cerr << "Reshape operatore having dynamic shape input is not supported" << std::endl;
      return ONNXIFI_STATUS_UNSUPPORTED_VERSION;
    }
    // Use static ONNX target shape data (from the constant literal constructed)
    // to build XLA target shape data 
    const tensorflow::gtl::ArraySlice<int64> onnxOperatorTargetShape = shapeDataIt->second->data<int64>();
    std::vector<int64> xlaOperatorTargetShape;
    const std::vector<Dimension>& originalShape = n.inputs().at(0)->sizes();
    int64_t negativeOneIndex = -1;
    for (auto i = 0; i < onnxOperatorTargetShape.size(); ++i)  {
      const int64& dim = onnxOperatorTargetShape.at(i);
      if (dim == -1)  {
          if(negativeOneIndex > -1) { //TODO: ENFORCE_GT
            std::cerr << "Invalid input: only one -1 allowed in input shape" << std::endl;
            return ONNXIFI_STATUS_INVALID_MODEL;
          }
          negativeOneIndex = i;
          xlaOperatorTargetShape.emplace_back(-1);
      } else if (dim == 0)  {
          const Dimension& originalDim = originalShape[i];
          if (!originalDim.is_int)  { //TODO: ENFORCE
            std::cerr << "Reshape operator's data shape is not known" << std::endl;
            return ONNXIFI_STATUS_UNSUPPORTED_SHAPE; 
          }
          xlaOperatorTargetShape.emplace_back(originalDim.dim);
      } else if (dim > 1)  {
          xlaOperatorTargetShape.emplace_back(dim);
      } else {  //TODO: Enforce
          std::cerr << "Dimension value cannot be less than -1" << std::endl;
          return ONNXIFI_STATUS_INVALID_MODEL;
      }
    }

    auto numElements = std::accumulate(originalShape.begin(), originalShape.end(), 1UL, std::multiplies<int64_t>());
    auto xlaProduct = std::accumulate(xlaOperatorTargetShape.begin(), xlaOperatorTargetShape.end(), 1UL, std::multiplies<int64>());
    if (negativeOneIndex == -1)  {
      if (xlaProduct != numElements)  { //TODO: enforce
          std::cerr << "Invalid shape to reshape to" << std::endl;
          return ONNXIFI_STATUS_INVALID_MODEL;
      }
    } else {
      if (numElements % (-xlaProduct) != 0)  {
          std::cerr << "Invalid shape to reshape to" << std::endl;
          return ONNXIFI_STATUS_INVALID_MODEL;
      }
      xlaOperatorTargetShape[negativeOneIndex] *= numElements / xlaProduct;
    }
    auto reshapeOp = builder.Reshape(valueToOp.at(n.inputs().at(0)), xlaOperatorTargetShape);
    valueToOp[n.outputs().at(0)] = reshapeOp;  
  }
  REGISTER_OPERATOR_TRANSLATOR(Reshape, translateReshape)



  onnxStatus translateRelu(const Node& n, XlaBuilder& builder, ValueOpMap& valueToOp, const ValueLiteralMap& valueToLiteral)  {
    auto input = valueToOp[n.inputs().at(0)];
    auto shape = builder.GetShape(input);
    if (!shape.ok())  {
      throw std::runtime_error("Internal error: Unexpected operation shape");
    }
    auto zero = builder.ConstantLiteral(*LiteralBase::CreateFromShape(shape.ValueOrDie()));
    auto maximum = builder.Max(input, zero);
    valueToOp[n.outputs().at(0)] = maximum;
    return ONNXIFI_STATUS_SUCCESS;
  }
  REGISTER_OPERATOR_TRANSLATOR(Relu, translateRelu)
 
  //TODO: Handle Undefined properly
  onnxStatus translateUndefined(const Node& n, XlaBuilder& builder, ValueOpMap& valueToOp, const ValueLiteralMap& valueToLiteral)  {
    return ONNXIFI_STATUS_SUCCESS;
  }
  REGISTER_OPERATOR_TRANSLATOR(Undefined, translateUndefined) 
}
