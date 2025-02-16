#pragma once

#include "Kara/Core/Render/BufferLayout.hpp"

namespace Kara {
namespace Core {
namespace Render {
class VertexBuffer {
public:
  virtual ~VertexBuffer() = default;

  virtual const BufferLayout &GetLayout() const = 0;
  virtual void SetLayout(const BufferLayout &aBufferLayout) = 0;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

} // namespace Render
} // namespace Core
} // namespace Kara