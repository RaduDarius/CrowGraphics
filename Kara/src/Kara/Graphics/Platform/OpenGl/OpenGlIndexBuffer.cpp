#include "pch.hpp"

#include "OpenGlIndexBuffer.hpp"

#include <glad/glad.h>

namespace Kara {
namespace Graphics {
OpenGlIndexBuffer::OpenGlIndexBuffer(uint32_t *aIndeces, std::size_t aSize)
    : mCount{static_cast<uint32_t>(aSize) / sizeof(uint32_t)} {
  glCreateBuffers(1, &mRendererId);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererId);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, aSize, aIndeces, GL_STATIC_DRAW);
}

OpenGlIndexBuffer::~OpenGlIndexBuffer() { glDeleteBuffers(1, &mRendererId); }

uint32_t OpenGlIndexBuffer::Count() const { return mCount; }

void OpenGlIndexBuffer::Bind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererId);
}

void OpenGlIndexBuffer::Unbind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

} // namespace Graphics
} // namespace Kara
