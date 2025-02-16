#include "pch.hpp"

#include "Renderer.hpp"

#include "Kara/Core/Platform/OpenGl/OpenGlIndexBuffer.hpp"
#include "Kara/Core/Platform/OpenGl/OpenGlVertexArray.hpp"
#include "Kara/Core/Platform/OpenGl/OpenGlVertexBuffer.hpp"
#include "Kara/Core/Render/BufferLayout.hpp"
#include "Kara/Log/Logger.hpp"

#include <glad/glad.h>

namespace Kara {
namespace Core {
namespace Render {
Renderer::Renderer(const RenderApi aRenderApi) : mRenderApi{aRenderApi} {
  CreateVertexArray();

  float vertices[] = {
      -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // Bottom-left
      0.5f,  -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Bottom-right
      0.0f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Top-center
  };
  CreateVertexBuffer(vertices, sizeof(vertices));

  {
    BufferLayout layout = {
        {BufferElementType::Float3, "inPosition"},
        {BufferElementType::Float4, "inColor"},
    };
    mVertexBuffer->SetLayout(layout);
  }

  mVertexArray->AddVertexBuffer(mVertexBuffer);

  uint32_t indeces[] = {0, 1, 2};
  CreateIndexBuffer(indeces, sizeof(indeces));
  mVertexArray->AddIndexBuffer(mIndexBuffer);

  mShader.reset(new Shader());

  mVertexBuffer->Unbind();
  mVertexArray->Unbind();
}

void Renderer::RenderTriangle() {
  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT);

  // Use shader program
  mShader->Bind();
  mVertexArray->Bind();
  glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}

void Renderer::CreateVertexArray() {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    mVertexArray.reset(new Platform::OpenGlVertexArray());
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
}

void Renderer::CreateIndexBuffer(uint32_t *aIndeces, uint32_t aSize) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    mIndexBuffer.reset(new Platform::OpenGlIndexBuffer(aIndeces, aSize));
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
}

void Renderer::CreateVertexBuffer(float *aVertices, uint32_t aSize) {
  switch (mRenderApi) {
  case RenderApi::None:
    break;

  case RenderApi::OpenGl:
    mVertexBuffer.reset(new Platform::OpenGlVertexBuffer(aVertices, aSize));
    break;

  default:
    KARA_CORE_ERROR("Unsupported render API");
    break;
  }
}

} // namespace Render
} // namespace Core
} // namespace Kara