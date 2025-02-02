#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/EventSystem/Event.hpp"

namespace Kara {
namespace EventSystem {
//! Events that are specific to a KEY:
//! KeyPressed, KeyReleased.

//! Base class for KEY related events that need to store a KEYCODE.
class KeyEvent : public Event {
 public:
  using KeyCode = int;

 protected:
  KeyEvent(const KeyCode aKeyCode) : mKeyCode{aKeyCode} {}

  virtual inline std::string ToString() const override {
    std::stringstream ss;
    ss << GetName() << ": " << mKeyCode << '\n';
    return ss.str();
  }

 private:
  KeyCode mKeyCode;
};

class KeyPressedEvent : public KeyEvent {
 public:
  KeyPressedEvent(const KeyCode aKeyCode, const uint32 aRepeatCount)
      : KeyEvent{aKeyCode}, mRepeatCount{aRepeatCount} {}

  EVENT_TYPE(KeyPressed);

 private:
  const uint32 mRepeatCount;
};

class KeyReleasedEvent : public KeyEvent {
 public:
  KeyReleasedEvent(const KeyCode aKeyCode) : KeyEvent{aKeyCode} {}

  EVENT_TYPE(KeyReleased);
};

}  // namespace EventSystem
}  // namespace Kara