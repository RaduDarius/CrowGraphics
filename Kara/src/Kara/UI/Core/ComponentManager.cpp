#include "pch.hpp"

#include "ComponentManager.hpp"

#include "Kara/Application.hpp"
#include "Kara/EventSystem/MouseEvent.hpp"
#include "Kara/UI/Internal/ButtonComponent.hpp"
#include "Kara/UI/Utils.hpp"

namespace Kara {
namespace UI {
namespace Core {
ComponentManager::ComponentManager() {
  Rect rect{0, 0, 100, 50};
  mComponents.emplace_back(new Internal::ButtonComponent(rect));

  rect.X += 2 * rect.Width;
  mComponents.emplace_back(new Internal::ButtonComponent(rect));

  rect.X += 2 * rect.Width;
  mComponents.emplace_back(new Component(rect));
}

void ComponentManager::OnEvent(EventSystem::Event &aEvent) {
  for (const auto &component : mComponents) {
    switch (aEvent.GetType()) {
    case EventSystem::EventType::MouseMoved: {
      auto &mouseEvent = dynamic_cast<EventSystem::MouseMovedEvent &>(aEvent);
      component->HandleMouseMoved(mouseEvent.GetPosition());
    } break;

    default:
      break;
    }
  }
}

void ComponentManager::Render() {
  for (const auto &component : mComponents) {
    component->Render();
  }
}
} // namespace Core
} // namespace UI
} // namespace Kara