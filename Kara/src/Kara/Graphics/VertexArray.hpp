#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/IndexBuffer.hpp"
#include "Kara/Graphics/VertexBuffer.hpp"

#include <memory>
#include <vector>

namespace Kara {
namespace Graphics {
class VertexBuffer;
class VertexArray {
public:
  using VBContainer = std::vector<Core::Ref<VertexBuffer>>;
  using IBContainer = Core::Ref<IndexBuffer>;

  virtual ~VertexArray() = default;

  virtual void AddIndexBuffer(const Core::Ref<IndexBuffer> &aBuffer) = 0;
  virtual void AddVertexBuffer(const Core::Ref<VertexBuffer> &aBuffer) = 0;

  virtual const IBContainer &GetIndexBuffer() const = 0;
  virtual const VBContainer &GetVertexBuffers() const = 0;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

} // namespace Graphics
} // namespace Kara