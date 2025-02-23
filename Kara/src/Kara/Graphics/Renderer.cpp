#include "pch.hpp"

#include "Renderer.hpp"

#include "Kara/Graphics/BufferLayout.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlIndexBuffer.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlShader.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlVertexArray.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlVertexBuffer.hpp"
#include "Kara/Log/Logger.hpp"

#include <glad/glad.h>

namespace Kara {
namespace Graphics {
Renderer::Renderer(const RenderApi aRenderApi) : mRenderApi{aRenderApi} {}

VertexArray *Renderer::CreateVertexArray() {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return new OpenGlVertexArray();
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }

  return nullptr;
}

IndexBuffer *Renderer::CreateIndexBuffer(uint32_t *aIndeces, uint32_t aSize) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return new OpenGlIndexBuffer(aIndeces, aSize);
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

VertexBuffer *Renderer::CreateVertexBuffer(float *aVertices, uint32_t aSize) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return new OpenGlVertexBuffer(aVertices, aSize);
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

Shader *Renderer::CreateShader() {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return new OpenGlShader();
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

} // namespace Graphics
} // namespace Kara
