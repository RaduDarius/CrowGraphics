#include "pch.hpp"

#include "MainLayer.hpp"

#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace UI {
MainLayer::MainLayer() : LayerSystem::Layer{"Main Layer"} {}

void MainLayer::OnAttach() {
  mComponentManager.reset(new UI::Core::ComponentManager());
}

void MainLayer::OnEvent(EventSystem::Event &aEvent) {
  KARA_CORE_TRACE("Printed from MainLayer: {0}", aEvent.ToString());
  mComponentManager->OnEvent(aEvent);
}

void MainLayer::OnRender() { mComponentManager->Render(); }

} // namespace UI
} // namespace Kara