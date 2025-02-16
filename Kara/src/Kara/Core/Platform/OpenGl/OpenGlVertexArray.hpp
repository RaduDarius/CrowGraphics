#pragma once

#include "Kara/Core/Render/BufferLayout.hpp"
#include "Kara/Core/Render/VertexArray.hpp"

#include <glad/glad.h>

#include <memory>

namespace Kara {
namespace Core {
namespace Render {
class VertexBuffer;
class IndexBuffer;
} // namespace Render
namespace Platform {
class OpenGlVertexArray : public Render::VertexArray {
public:
  OpenGlVertexArray();
  ~OpenGlVertexArray() override;

  void
  AddIndexBuffer(const std::shared_ptr<Render::IndexBuffer> &aBuffer) override;
  void AddVertexBuffer(
      const std::shared_ptr<Render::VertexBuffer> &aBuffer) override;

  void Bind() const override;
  void Unbind() const override;

private:
  GLenum ElementTypeToOpenGlType(Render::BufferElementType aType);

  std::vector<std::shared_ptr<Render::VertexBuffer>> mVertexBuffers;
  std::shared_ptr<Render::IndexBuffer> mIndexBuffer;

  unsigned int mRenderId;
};

} // namespace Platform
} // namespace Core
} // namespace Kara