#include "pch.hpp"

#include "ComponentManager.hpp"

#include "Kara/Application.hpp"
#include "Kara/Log/Logger.hpp"
#include "Kara/UI/Components/Desktop.hpp"
#include "Kara/UI/Utils.hpp"

namespace Kara {
namespace UI {
ComponentManager *ComponentManager::smInstance = nullptr;

ComponentManager *ComponentManager::Get() {
  if (!smInstance) {
    smInstance = new ComponentManager();
  }
  return smInstance;
}

void ComponentManager::CreateRootComponent() {
  mDesktop.reset(ComponentManager::CreateComponent<Desktop>(
      nullptr, {0, 0, Application::Get()->GetWindowSize()}));
}

void ComponentManager::Render() {
  mDesktop->TraverseReverse(
      [](Component &aComponent) { aComponent.OnRender(); });
}

} // namespace UI
} // namespace Kara