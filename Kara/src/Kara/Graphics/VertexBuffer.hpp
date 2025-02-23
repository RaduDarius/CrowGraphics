#pragma once

#include "Kara/Graphics/BufferLayout.hpp"

namespace Kara {
namespace Graphics {
class VertexBuffer {
public:
  virtual ~VertexBuffer() = default;

  virtual const BufferLayout &GetLayout() const = 0;
  virtual void SetLayout(const BufferLayout &aBufferLayout) = 0;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

} // namespace Graphics
} // namespace Kara