#include "pch.hpp"

#include "Renderer.hpp"

#include "Kara/Core/Platform/OpenGl/OpenGlIndexBuffer.hpp"
#include "Kara/Core/Platform/OpenGl/OpenGlShader.hpp"
#include "Kara/Core/Platform/OpenGl/OpenGlVertexArray.hpp"
#include "Kara/Core/Platform/OpenGl/OpenGlVertexBuffer.hpp"
#include "Kara/Core/Render/BufferLayout.hpp"
#include "Kara/Log/Logger.hpp"

#include <glad/glad.h>

namespace Kara {
namespace Core {
namespace Render {
Renderer::Renderer(const RenderApi aRenderApi) : mRenderApi{aRenderApi} {}

VertexArray *Renderer::CreateVertexArray() {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return new Platform::OpenGlVertexArray();
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
    return new Platform::OpenGlIndexBuffer(aIndeces, aSize);
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
    return new Platform::OpenGlVertexBuffer(aVertices, aSize);
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
    return new Platform::OpenGlShader();
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

} // namespace Render
} // namespace Core
} // namespace Kara