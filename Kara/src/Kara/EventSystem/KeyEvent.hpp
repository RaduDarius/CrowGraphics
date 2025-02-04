#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/EventSystem/KeyCode.hpp"

namespace Kara {
namespace EventSystem {
//! Events that are specific to a KEY:
//! KeyPressed, KeyReleased.

//! Base class for KEY related events that need to store a KEYCODE.
class KeyEvent : public Event {
 public:
  inline KeyCode GetKeyCode() const { return mKeyCode; }

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

  inline uint32 GetDuration() const { return mRepeatCount; }

  EVENT_TYPE(KeyPressed);

 private:
  const uint32 mRepeatCount;
};

class KeyReleasedEvent : public KeyEvent {
 public:
  KeyReleasedEvent(const KeyCode aKeyCode) : KeyEvent{aKeyCode} {}

  EVENT_TYPE(KeyReleased);
};

class KeyTypedEvent : public KeyEvent {
public:
  KeyTypedEvent(const KeyCode aKeyCode) : KeyEvent{aKeyCode} {}

  EVENT_TYPE(KeyTyped);
};

}  // namespace EventSystem
}  // namespace Kara