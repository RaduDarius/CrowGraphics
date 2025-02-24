#include "pch.hpp"

#include "Component.hpp"

#include "Kara/Application.hpp"
#include "Kara/Graphics/BufferLayout.hpp"
#include "Kara/Graphics/Camera.hpp"
#include "Kara/Graphics/Command.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Kara {
namespace UI {
Component::Component(const Rect &aRect) : mRect{aRect} {
  mRenderer.reset(new Graphics::Renderer(Graphics::RenderApi::OpenGl));

  mVertexArray = mRenderer->CreateVertexArray();

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

  Core::Ref<Graphics::VertexBuffer> vertexBuffer;
  vertexBuffer = mRenderer->CreateVertexBuffer(vertices, sizeof(vertices));

  Graphics::BufferLayout layout = {
      {Graphics::BufferElementType::Float3, "inPosition"},
  };
  vertexBuffer->SetLayout(layout);

  mVertexArray->AddVertexBuffer(vertexBuffer);

  uint32_t indeces[] = {0, 1, 2, 2, 3, 0};
  Core::Ref<Graphics::IndexBuffer> indexBuffer;
  indexBuffer = mRenderer->CreateIndexBuffer(indeces, sizeof(indeces));
  mVertexArray->AddIndexBuffer(indexBuffer);

  mShader = mRenderer->CreateShader(Graphics::Shader::Type::Basic);
}

void Component::Render() {
  mShader->Bind();
  const auto screenSize = Application::Get()->GetWindow()->GetSize();
  const auto camera =
      Graphics::Camera(0.0f, static_cast<float>(screenSize.mWidth),
                       static_cast<float>(screenSize.mHeight), 0.0f);
  mShader->UploadUniformMat4("uVP", camera.GetVPMat());
  mShader->UploadUniformVec4("uColor", mColor);

  mVertexArray->Bind();
  Graphics::Command::Draw(mVertexArray);
}

} // namespace UI
} // namespace Kara