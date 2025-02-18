#pragma once

#include "Kara/Core/Core.hpp"
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
  using VBContainer = std::vector<Ref<Render::VertexBuffer>>;
  using IBContainer = Ref<Render::IndexBuffer>;

  virtual ~VertexArray() = default;

  virtual void AddIndexBuffer(const Ref<IndexBuffer> &aBuffer) = 0;
  virtual void AddVertexBuffer(const Ref<VertexBuffer> &aBuffer) = 0;

  virtual const IBContainer &GetIndexBuffer() const = 0;
  virtual const VBContainer &GetVertexBuffers() const = 0;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

} // namespace Render
} // namespace Core
} // namespace Kara