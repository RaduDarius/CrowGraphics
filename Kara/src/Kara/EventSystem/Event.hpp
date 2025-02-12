#pragma once

#include "Kara/Core/Core.hpp"

namespace Kara {
namespace EventSystem {
enum class EventType {
  None = 0, // Invalid

  // Window Events
  WindowClosed,
  WindowResized,
  WindowMoved,

  // Key Events
  KeyPressed,
  KeyReleased,
  KeyTyped,

  // Mouse Events
  MouseButtonPressed,
  MouseButtonReleased,
  MouseMoved,
  MouseScrolled,
};

#define EVENT_TYPE(type)                                                       \
  static EventType GetStaticType() { return EventType::##type; }               \
  virtual EventType GetType() const override { return GetStaticType(); }       \
  virtual const char *GetName() const override { return #type; }

class Event {
  friend class Dispatcher;

public:
  virtual const char *GetName() const = 0;
  virtual EventType GetType() const = 0;
  virtual std::string ToString() const = 0;

  inline bool IsHandled() const { return mIsHandled; }

private:
  bool mIsHandled{false};
};

inline std::ostream &operator<<(std::ostream &os, const Event &e) {
  return os << e.GetName();
}

} // namespace EventSystem
} // namespace Kara