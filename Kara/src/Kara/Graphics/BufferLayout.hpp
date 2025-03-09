#pragma once

#include <stdint.h>
#include <string>
#include <vector>

namespace Kara {
namespace Graphics {
enum class BufferElementType : uint8_t { None, Float2, Float3, Float4 };

struct BufferElement {
  BufferElementType Type;
  std::string Name;
  uint32_t Size{0};
  uint32_t Offset{0};
  bool IsNormalized{false};

  uint32_t ComponentCount{0};

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
} // namespace Graphics
} // namespace Kara