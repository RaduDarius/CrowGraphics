#include "pch.hpp"

#include "ComponentManager.hpp"

#include "Kara/Application.hpp"
#include "Kara/Events/MouseEvent.hpp"
#include "Kara/UI/ButtonComponent.hpp"
#include "Kara/UI/Utils.hpp"

namespace Kara {
namespace UI {
ComponentManager::ComponentManager() {
  Rect rect{0, 0, 100, 50};
  mComponents.emplace_back(new ButtonComponent(rect));

  rect.X += 2 * rect.Width;
  mComponents.emplace_back(new ButtonComponent(rect));

  rect.X += 2 * rect.Width;
  mComponents.emplace_back(new Component(rect));
}

void ComponentManager::OnUpdate() {
  for (const auto &component : mComponents) {
    component->OnUpdate();
  }
}

void ComponentManager::Render() {
  for (const auto &component : mComponents) {
    component->Render();
  }
}
} // namespace UI
} // namespace Kara