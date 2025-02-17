#include "pch.hpp"

#include "Component.hpp"

#include "Kara/Application.hpp"
#include "Kara/Core/Render/BufferLayout.hpp"
#include "Kara/Core/Render/Command.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Kara {
namespace UI {
namespace Core {
using namespace Kara::Core;

Component::Component(const Rect &aRect) : mRect{aRect} {
  mRenderer.reset(new Render::Renderer(Kara::Core::Render::RenderApi::OpenGl));

  mVertexArray.reset(mRenderer->CreateVertexArray());

  const auto normalizedRect = mRect.Normalize();

  float vertices[] = {
      // Position 0
      normalizedRect.X, normalizedRect.Y, 0.0f,
      // Color 0
      0.0f, 0.0f, 1.0f, 1.0f,
      // Position 1
      normalizedRect.X + normalizedRect.Width, normalizedRect.Y, 0.0f,
      // Color 1s
      0.0f, 0.0f, 1.0f, 1.0f,
      // Position 2
      normalizedRect.X + normalizedRect.Width,
      normalizedRect.Y + normalizedRect.Height, 0.0f,
      // Color 2
      0.0f, 0.0f, 1.0f, 1.0f,
      // Position 3
      normalizedRect.X, normalizedRect.Y + normalizedRect.Height, 0.0f,
      // Color 3
      0.0f, 0.0f, 1.0f, 1.0f};

  std::shared_ptr<Render::VertexBuffer> vertexBuffer;
  vertexBuffer.reset(mRenderer->CreateVertexBuffer(vertices, sizeof(vertices)));

  Render::BufferLayout layout = {
      {Render::BufferElementType::Float3, "inPosition"},
      {Render::BufferElementType::Float4, "inColor"},
  };
  vertexBuffer->SetLayout(layout);

  mVertexArray->AddVertexBuffer(vertexBuffer);

  uint32_t indeces[] = {0, 1, 2, 2, 3, 0};
  std::shared_ptr<Render::IndexBuffer> indexBuffer;
  indexBuffer.reset(mRenderer->CreateIndexBuffer(indeces, sizeof(indeces)));
  mVertexArray->AddIndexBuffer(indexBuffer);

  mShader.reset(new Render::Shader());

  auto projection = glm::ortho(0.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f);
  mShader->AddProjectionMat(projection);
}

void Component::Render() {
  mShader->Bind();
  mVertexArray->Bind();
  Render::Command::Draw(mVertexArray);
}

} // namespace Core
} // namespace UI
} // namespace Kara