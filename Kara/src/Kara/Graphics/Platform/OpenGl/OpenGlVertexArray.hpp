#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/BufferLayout.hpp"
#include "Kara/Graphics/IndexBuffer.hpp"
#include "Kara/Graphics/VertexArray.hpp"
#include "Kara/Graphics/VertexBuffer.hpp"

#include <glad/glad.h>

#include <memory>

namespace Kara {
namespace Graphics {
class OpenGlVertexArray : public VertexArray {
public:
  OpenGlVertexArray();
  ~OpenGlVertexArray() override;

  void AddIndexBuffer(const Core::Ref<IndexBuffer> &aBuffer) override;
  void AddVertexBuffer(const Core::Ref<VertexBuffer> &aBuffer) override;

  const IBContainer &GetIndexBuffer() const override;
  const VBContainer &GetVertexBuffer() const override;

  void Bind() const override;
  void Unbind() const override;

private:
  GLenum ElementTypeToOpenGlType(BufferElementType aType);

  VBContainer mVertexBuffer;
  IBContainer mIndexBuffer;

  unsigned int mRenderId;
};

} // namespace Graphics
} // namespace Kara