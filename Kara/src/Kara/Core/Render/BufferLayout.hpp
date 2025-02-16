#pragma once

#include <stdint.h>
#include <string>
#include <vector>

namespace Kara {
namespace Core {
namespace Render {
enum class BufferElementType : uint8_t { None, Float3, Float4 };

struct BufferElement {
  BufferElementType mType;
  std::string mName;
  uint32_t mSize{0};
  uint32_t mOffset{0};
  bool mIsNormalized{false};

  uint32_t mComponentCount{0};

  BufferElement(const BufferElementType aType, const std::string &aName);

private:
  void SetSizeAndComponentCount();
};

class BufferLayout {
  using ElemList = std::vector<BufferElement>;

public:
  BufferLayout(const std::initializer_list<BufferElement> &aElements);

  inline const ElemList &GetElements() const { return mElements; }
  inline uint32_t GetStride() const { return mStride; }

  ElemList::iterator begin() { return mElements.begin(); }
  ElemList::iterator end() { return mElements.end(); }

  ElemList::const_iterator begin() const { return mElements.begin(); }
  ElemList::const_iterator end() const { return mElements.end(); }

private:
  void ComputeOffsetAndStride();

  ElemList mElements;

  uint32_t mStride{0};
};
} // namespace Render
} // namespace Core
} // namespace Kara