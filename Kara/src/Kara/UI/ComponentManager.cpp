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
  mDesktop.reset(
      new Desktop(nullptr, {0, 0, Application::Get()->GetWindowSize()}, {}));
}

} // namespace UI
} // namespace Kara