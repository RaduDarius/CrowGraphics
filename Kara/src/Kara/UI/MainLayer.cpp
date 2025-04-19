#include "pch.hpp"

#include "MainLayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/Graphics/Render2D.hpp"
#include "Kara/UI/ComponentManager.hpp"

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
  Graphics::Render2D::BeginFrame();
  ComponentManager::Get()->Render();
  Graphics::Render2D::EndFrame(mCamera.GetVPMat());
}

} // namespace UI
} // namespace Kara