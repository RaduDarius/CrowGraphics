#pragma once

#include "Kara/Core/Render/IndexBuffer.hpp"
#include "Kara/Core/Render/VertexBuffer.hpp"

#include <memory>
#include <vector>

namespace Kara {
namespace Core {
namespace Render {
class VertexBuffer;
class VertexArray {
public:
  using VBContainer = std::vector<std::shared_ptr<Render::VertexBuffer>>;
  using IBContainer = std::shared_ptr<Render::IndexBuffer>;

  virtual ~VertexArray() = default;

  virtual void AddIndexBuffer(const std::shared_ptr<IndexBuffer> &aBuffer) = 0;
  virtual void
  AddVertexBuffer(const std::shared_ptr<VertexBuffer> &aBuffer) = 0;

  virtual const IBContainer &GetIndexBuffer() const = 0;
  virtual const VBContainer &GetVertexBuffers() const = 0;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

} // namespace Render
} // namespace Core
} // namespace Kara