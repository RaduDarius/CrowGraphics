#pragma once

namespace Kara {
namespace EventSystem {
enum class EventType {
  None = 0,  // Invalid

  // Window Events
  WindowClose,
  WindowResize,
  WindowMoved,

  // Key Events
  KeyPressed,
  KeyReleaased,

  // Mouse Events
  MouseButtonPressed,
  MouseButtonReleased,
  MouseMoved,
  MouseScrolled,
};

}
}  // namespace Kara