#include "pch.hpp"

#include "BufferLayout.hpp"

#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace Graphics {
BufferElement::BufferElement(const BufferElementType aType,
                             const std::string &aName)
    : Type{aType}, Name{aName} {
  SetSizeAndComponentCount();
}

void BufferElement::SetSizeAndComponentCount() {
  ComponentCount = 0;
  Size = 0;

  switch (Type) {
  case BufferElementType::None:
    break;

  case BufferElementType::Float2:
    ComponentCount = 2;
    Size = ComponentCount * sizeof(float);
    break;

  case BufferElementType::Float3:
    ComponentCount = 3;
    Size = ComponentCount * sizeof(float);
    break;

  case BufferElementType::Float4:
    ComponentCount = 4;
    Size = ComponentCount * sizeof(float);
    break;

  default:
    KARA_CORE_ASSERT(false, "Unknown buffer element type!");
    break;
  }
}

BufferLayout::BufferLayout(
    const std::initializer_list<BufferElement> &aElements)
    : mElements{aElements} {
  ComputeOffsetAndStride();
}

void BufferLayout::ComputeOffsetAndStride() {
  auto offset{0};
  mStride = 0;
  for (auto &element : mElements) {
    element.Offset = offset;
    offset += element.Size;

    mStride += element.Size;
  }
}

} // namespace Graphics
} // namespace Kara