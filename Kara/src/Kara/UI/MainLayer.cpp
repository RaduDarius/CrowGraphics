#include "pch.hpp"

#include "MainLayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/Graphics/RenderCommand.hpp"
#include "Kara/Graphics/Renderer.hpp"
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
}

void MainLayer::OnUpdate() {
  for (const auto &renderObject : ComponentManager::GetRenderObjects()) {
    renderObject->VertexArray->Bind();
    renderObject->Material->Bind();
    const auto &shader = renderObject->Material->GetShader();
    shader->UploadUniformMat4("uVP", mCamera.GetVPMat());
    shader->UploadUniformMat4("uModel", glm::mat4(1.0f));

    Graphics::RenderCommand::Draw(renderObject->VertexArray);
  }
}

} // namespace UI
} // namespace Kara