#include "pch.hpp"

#include "MainLayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/Graphics/Command.hpp"
#include "Kara/UI/ComponentManager.hpp"

#include <glm/glm.hpp>

namespace Kara {
namespace UI {
MainLayer::MainLayer()
    : Layers::Layer{"Main UI Layer"},
      mCamera{Graphics::Camera{
          0.0f, (float)Application::Get()->GetWindowSize().Width,
          (float)Application::Get()->GetWindowSize().Height, 0.0f}} {
  ComponentManager::Get()->CreateRootComponent();

  mRenderer.reset(new Graphics::Renderer(Graphics::RenderApi::OpenGl));
  mShader = mRenderer->CreateShader(Graphics::Shader::Type::Basic);
}

void MainLayer::OnUpdate() {
  for (const auto &prop : mRenderProps) {
    prop.VertexArray->Bind();

    mShader->Bind();
    mShader->UploadUniformMat4("uVP", mCamera.GetVPMat());
    mShader->UploadUniformMat4("uModel", glm::mat4(1.0f));
    mShader->UploadUniformVec4("uColor", prop.Color);

    Graphics::Command::Draw(prop.VertexArray);
  }
}

} // namespace UI
} // namespace Kara