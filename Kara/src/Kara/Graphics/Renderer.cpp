#include "pch.hpp"

#include "Renderer.hpp"

#include "Kara/Graphics/BufferLayout.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlFontTexture.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlIndexBuffer.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlShader.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlTexture.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlVertexArray.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlVertexBuffer.hpp"
#include "Kara/Graphics/RenderCommand.hpp"
#include "Kara/Log/Logger.hpp"

#include <glad/glad.h>

namespace Kara {
namespace Graphics {
RenderApi Renderer::mRenderApi = RenderApi::OpenGl;

Core::Ref<VertexArray> Renderer::CreateVertexArray() {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return std::make_shared<OpenGlVertexArray>();
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }

  return nullptr;
}

Core::Ref<IndexBuffer> Renderer::CreateIndexBuffer(uint32_t *aIndeces,
                                                   std::size_t aSize) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return std::make_shared<OpenGlIndexBuffer>(aIndeces, aSize);
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

Core::Ref<VertexBuffer> Renderer::CreateVertexBuffer(float *aVertices,
                                                     std::size_t aSize) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return std::make_shared<OpenGlVertexBuffer>(aVertices, aSize);
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

Core::Ref<Shader> Renderer::CreateShader(const Shader::Type aShaderType) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return std::make_shared<OpenGlShader>(aShaderType);
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

Core::Ref<Texture> Renderer::CreateTexture(const std::string_view &aPath) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return std::make_shared<OpenGlTexture>(aPath);
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

Core::Ref<FontTexture>
Renderer::CreateFontTexture(const Font::FontFace &aFont) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    return std::make_shared<OpenGlFontTexture>(aFont);

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
  return nullptr;
}

} // namespace Graphics
} // namespace Kara
