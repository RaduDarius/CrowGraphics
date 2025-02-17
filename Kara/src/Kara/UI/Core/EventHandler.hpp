#pragma once

#include "Kara/EventSystem/MouseEvent.hpp"

namespace Kara {
namespace UI {
namespace Core {
//! @brief Interface for componenets to handle various event types.
class EventHandler {
public:
  using Position = EventSystem::MouseMovedEvent::Position;

  virtual void HandleMouseMoved(const Position &aNewPosition) {}
};
} // namespace Core
} // namespace UI
} // namespace Kara