#include "onnx_xla/operator_registry.h"

namespace onnx_xla {

OperatorRegistry::OperatorRegisterOnce::OperatorRegisterOnce(
    const Symbol& nodeKind,
    TranslationFunction translator) {
  auto& map = OperatorRegistry::map();
  if (!map.insert(std::pair<Symbol, TranslationFunction>(nodeKind, translator))
           .second) {
    throw std::runtime_error("Registry error: Operator added more than once");
  }
}

onnxStatus OperatorRegistry::translate(const Node& n,
                                       XlaBuilder& builder,
                                       ValueOpMap& valueToOp) {
  auto& map = OperatorRegistry::map();
  auto it = map.find(n.kind());
  if (it != map.end()) {
    return it->second(n, builder, valueToOp);
  } else {
    std::cerr << "Operator translator not found" << std::endl;
    return ONNXIFI_STATUS_UNSUPPORTED_OPERATOR;
  }
}

OperatorRegistry& OperatorRegistry::registry() {
  static OperatorRegistry registry_;
  return registry_;
}

TranslationMap& OperatorRegistry::map() {
  static TranslationMap map;
  return map;
}

std::vector<int64_t> OperatorRegistry::parseOnnxInputSizes(const Node& n,
                                                           size_t inputIndex) {
  std::vector<int64_t> shapeInts;
  const auto& shapeDims = n.inputs().at(inputIndex)->sizes();
  if (shapeDims.size() == 0) {
    throw std::runtime_error("Missing shape");
  }

  for (const auto& dimension : shapeDims) {
    if (!dimension.is_int) {
      throw std::runtime_error("Invalid dimension");
    }
    shapeInts.emplace_back(dimension.dim);
  }

  return shapeInts;
}
}
