#include "pch.hpp"

#include "OpenGlVertexArray.hpp"

#include "Kara/Graphics/VertexBuffer.hpp"
#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace Graphics {
OpenGlVertexArray::OpenGlVertexArray() {
  glCreateVertexArrays(1, &mRenderId);
  glBindVertexArray(mRenderId);
}

OpenGlVertexArray::~OpenGlVertexArray() { glDeleteVertexArrays(1, &mRenderId); }

void OpenGlVertexArray::AddIndexBuffer(const Core::Ref<IndexBuffer> &aBuffer) {
  mIndexBuffer = aBuffer;

  glBindVertexArray(mRenderId);
  aBuffer->Bind();
}

void OpenGlVertexArray::AddVertexBuffer(
    const Core::Ref<VertexBuffer> &aBuffer) {
  mVertexBuffers.emplace_back(aBuffer);

  glBindVertexArray(mRenderId);
  aBuffer->Bind();

  auto index{0};
  const auto &layout = aBuffer->GetLayout();
  for (const auto &element : layout) {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, element.ComponentCount,
                          ElementTypeToOpenGlType(element.Type),
                          element.IsNormalized, layout.GetStride(),
                          reinterpret_cast<const void *>(element.Offset));

    index++;
  }
}

const OpenGlVertexArray::IBContainer &
OpenGlVertexArray::GetIndexBuffer() const {
  return mIndexBuffer;
}

const OpenGlVertexArray::VBContainer &
OpenGlVertexArray::GetVertexBuffers() const {
  return mVertexBuffers;
}

void OpenGlVertexArray::Bind() const { glBindVertexArray(mRenderId); }

void OpenGlVertexArray::Unbind() const { glBindVertexArray(0); }

GLenum OpenGlVertexArray::ElementTypeToOpenGlType(BufferElementType aType) {
  switch (aType) {
  case BufferElementType::Float2:
  case BufferElementType::Float3:
  case BufferElementType::Float4:
    return GL_FLOAT;
  default:
    KARA_CORE_ASSERT(false, "Unable to convert to opengl type !");
    return 0;
  }
}

} // namespace Graphics
} // namespace Kara