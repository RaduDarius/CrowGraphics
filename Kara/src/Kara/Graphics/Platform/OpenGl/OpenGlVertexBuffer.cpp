#include "pch.hpp"

#include "OpenGlVertexBuffer.hpp"

#include <glad/glad.h>

namespace Kara {
namespace Graphics {
OpenGlVertexBuffer::OpenGlVertexBuffer(float *aVertices, uint32_t aSize) {
  glCreateBuffers(1, &mRendererId);
  glBindBuffer(GL_ARRAY_BUFFER, mRendererId);
  glBufferData(GL_ARRAY_BUFFER, aSize, aVertices, GL_STATIC_DRAW);
}

OpenGlVertexBuffer::~OpenGlVertexBuffer() { glDeleteBuffers(1, &mRendererId); }

void OpenGlVertexBuffer::Bind() const {
  glBindBuffer(GL_ARRAY_BUFFER, mRendererId);
}

void OpenGlVertexBuffer::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

void OpenGlVertexBuffer::SetLayout(const BufferLayout &aLayout) {
  mLayout = aLayout;
}

} // namespace Graphics
} // namespace Kara
