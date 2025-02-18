#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Render/BufferLayout.hpp"
#include "Kara/Core/Render/IndexBuffer.hpp"
#include "Kara/Core/Render/VertexArray.hpp"
#include "Kara/Core/Render/VertexBuffer.hpp"

#include <glad/glad.h>

#include <memory>

namespace Kara {
namespace Core {
namespace Platform {
class OpenGlVertexArray : public Render::VertexArray {
public:
  OpenGlVertexArray();
  ~OpenGlVertexArray() override;

  void AddIndexBuffer(const Ref<Render::IndexBuffer> &aBuffer) override;
  void AddVertexBuffer(const Ref<Render::VertexBuffer> &aBuffer) override;

  const IBContainer &GetIndexBuffer() const override;
  const VBContainer &GetVertexBuffers() const override;

  void Bind() const override;
  void Unbind() const override;

private:
  GLenum ElementTypeToOpenGlType(Render::BufferElementType aType);

  VBContainer mVertexBuffers;
  IBContainer mIndexBuffer;

  unsigned int mRenderId;
};

} // namespace Platform
} // namespace Core
} // namespace Kara