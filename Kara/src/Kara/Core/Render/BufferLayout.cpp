#include "pch.hpp"

#include "BufferLayout.hpp"

#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace Core {
namespace Render {
BufferElement::BufferElement(const BufferElementType aType,
                             const std::string &aName)
    : mType{aType}, mName{aName} {
  SetSizeAndComponentCount();
}

void BufferElement::SetSizeAndComponentCount() {
  mComponentCount = 0;
  mSize = 0;

  switch (mType) {
  case BufferElementType::None:
    break;

  case BufferElementType::Float3:
    mComponentCount = 3;
    mSize = mComponentCount * sizeof(float);
    break;

  case BufferElementType::Float4:
    mComponentCount = 4;
    mSize = mComponentCount * sizeof(float);
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
    element.mOffset = offset;
    offset += element.mSize;

    mStride += element.mSize;
  }
}

} // namespace Render
} // namespace Core
} // namespace Kara