#pragma once

#include "Kara/EventSystem/KeyEvent.hpp"
#include "Kara/EventSystem/MouseEvent.hpp"
#include "Kara/EventSystem/WindowEvent.hpp"

namespace Kara {
namespace UI {
class EventHandler {
public:
  void OnEvent(EventSystem::Event &aEvent);

  //! Mouse Events
  bool OnMouseButtonPressedEvent(EventSystem::MouseButtonPressedEvent &aEvent);
  bool
  OnMouseButtonReleasedEvent(EventSystem::MouseButtonReleasedEvent &aEvent);
  bool OnMouseMovedEvent(EventSystem::MouseMovedEvent &aEvent);
  bool OnMouseScrolledEvent(EventSystem::MouseScrolledEvent &aEvent);

  //! Key Events
  bool OnKeyPressedEvent(EventSystem::KeyPressedEvent &aEvent);
  bool OnKeyReleasedEvent(EventSystem::KeyReleasedEvent &aEvent);
  bool OnKeyTypedEvent(EventSystem::KeyTypedEvent &aEvent);

  //! Window Events
  bool OnWindowResizedEvent(EventSystem::WindowResizedEvent &aEvent);
};
} // namespace UI
} // namespace Kara
