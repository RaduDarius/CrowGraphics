#include "pch.hpp"

#include "OpenGlVertexArray.hpp"

#include "Kara/Core/Render/VertexBuffer.hpp"
#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace Core {
namespace Platform {
OpenGlVertexArray::OpenGlVertexArray() {
  glCreateVertexArrays(1, &mRenderId);
  glBindVertexArray(mRenderId);
}

OpenGlVertexArray::~OpenGlVertexArray() { glDeleteVertexArrays(1, &mRenderId); }

void OpenGlVertexArray::AddIndexBuffer(
    const Ref<Render::IndexBuffer> &aBuffer) {
  mIndexBuffer = aBuffer;

  glBindVertexArray(mRenderId);
  aBuffer->Bind();
}

void OpenGlVertexArray::AddVertexBuffer(
    const Ref<Render::VertexBuffer> &aBuffer) {
  mVertexBuffers.emplace_back(aBuffer);

  glBindVertexArray(mRenderId);
  aBuffer->Bind();

  auto index{0};
  const auto &layout = aBuffer->GetLayout();
  for (const auto &element : layout) {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, element.mComponentCount,
                          ElementTypeToOpenGlType(element.mType),
                          element.mIsNormalized, layout.GetStride(),
                          reinterpret_cast<const void *>(element.mOffset));

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

GLenum
OpenGlVertexArray::ElementTypeToOpenGlType(Render::BufferElementType aType) {
  switch (aType) {
  case Render::BufferElementType::Float3:
  case Render::BufferElementType::Float4:
    return GL_FLOAT;
  default:
    KARA_CORE_ASSERT(false, "Unable to convert to opengl type !");
    return 0;
  }
}

} // namespace Platform
} // namespace Core
} // namespace Kara