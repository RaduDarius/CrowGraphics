#include "pch.hpp"

#include "Component.hpp"

#include "Kara/Application.hpp"
#include "Kara/Core/Render/BufferLayout.hpp"
#include "Kara/Core/Render/Camera.hpp"
#include "Kara/Core/Render/Command.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Kara {
namespace UI {
namespace Core {
using namespace Kara::Core;

Component::Component(const Rect &aRect) : mRect{aRect} {
  mRenderer.reset(new Render::Renderer(Render::RenderApi::OpenGl));

  mVertexArray.reset(mRenderer->CreateVertexArray());

  float vertices[] = {// Position 0
                      static_cast<float>(mRect.X), static_cast<float>(mRect.Y),
                      0.0f,
                      // Position 1
                      static_cast<float>(mRect.X + mRect.Width),
                      static_cast<float>(mRect.Y), 0.0f,
                      // Position 2
                      static_cast<float>(mRect.X + mRect.Width),
                      static_cast<float>(mRect.Y + mRect.Height), 0.0f,
                      // Position 3
                      static_cast<float>(mRect.X),
                      static_cast<float>(mRect.Y + mRect.Height), 0.0f};

  Ref<Render::VertexBuffer> vertexBuffer;
  vertexBuffer.reset(mRenderer->CreateVertexBuffer(vertices, sizeof(vertices)));

  Render::BufferLayout layout = {
      {Render::BufferElementType::Float3, "inPosition"},
  };
  vertexBuffer->SetLayout(layout);

  mVertexArray->AddVertexBuffer(vertexBuffer);

  uint32_t indeces[] = {0, 1, 2, 2, 3, 0};
  Ref<Render::IndexBuffer> indexBuffer;
  indexBuffer.reset(mRenderer->CreateIndexBuffer(indeces, sizeof(indeces)));
  mVertexArray->AddIndexBuffer(indexBuffer);

  mShader.reset(mRenderer->CreateShader());
}

void Component::Render() {
  mShader->Bind();
  const auto screenSize = Application::Get()->GetWindow()->GetSize();
  const auto camera =
      Render::Camera(0.0f, static_cast<float>(screenSize.mWidth),
                     static_cast<float>(screenSize.mHeight), 0.0f);
  mShader->UploadUniformMat4("uVP", camera.GetVPMat());
  mShader->UploadUniformVec4("uColor", mColor);

  mVertexArray->Bind();
  Render::Command::Draw(mVertexArray);
}

} // namespace Core
} // namespace UI
} // namespace Kara