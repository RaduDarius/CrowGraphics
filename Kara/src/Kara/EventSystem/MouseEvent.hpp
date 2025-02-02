#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Types.hpp"
#include "Kara/EventSystem/Event.hpp"

namespace Kara {
namespace EventSystem {
//! Events that are specific to the MOUSE:
//! MouseMoved, MouseScrolled, MouseButtonPressed, MouseButtonReleased.

class MouseMovedEvent : public Event {
 public:
  using Position = Point;

  MouseMovedEvent(const float aX, const float aY) : mPosition{aX, aY} {}
  MouseMovedEvent(const Position& aPosition) : mPosition{aPosition} {}

  inline Position GetPosition() { return mPosition; }
  inline float GetX() { return mPosition.x; }
  inline float GetY() { return mPosition.y; }

  virtual inline std::string ToString() const override {
    std::stringstream ss;
    ss << GetName() << ": " << mPosition << '\n';
    return ss.str();
  }

  EVENT_TYPE(MouseMoved);

 private:
  Position mPosition;
};

class MouseScrolledEvent : public Event {
 public:
  using Offset = Point;

  MouseScrolledEvent(const float aXOffset, const float aYOffset)
      : mOffset{aXOffset, aYOffset} {}
  MouseScrolledEvent(const Offset& aOffset) : mOffset{aOffset} {}

  inline Offset GetPosition() { return mOffset; }
  inline float GetXOffset() { return mOffset.x; }
  inline float GetYOffset() { return mOffset.y; }

  virtual inline std::string ToString() const override {
    std::stringstream ss;
    ss << GetName() << ": " << mOffset << '\n';
    return ss.str();
  }

  EVENT_TYPE(MouseScrolled);

 private:
  Offset mOffset;
};

//! Base class for BUTTON related events that need to store a BUTTONCODE.
class MouseButtonEvent : public Event {
 public:
  using ButtonCode = int;

  inline ButtonCode GetButton() const { return mButton; }

  virtual inline std::string ToString() const override {
    std::stringstream ss;
    ss << GetName() << ": " << mButton << '\n';
    return ss.str();
  }

 protected:
  MouseButtonEvent(const ButtonCode aButton) : mButton{aButton} {}

 private:
  ButtonCode mButton;
};

class MouseButtonPressedEvent : public MouseButtonEvent {
 public:
  MouseButtonPressedEvent(const ButtonCode aButton)
      : MouseButtonEvent{aButton} {}

  EVENT_TYPE(MouseButtonPressed);
};

class MouseButtonReleasedEvent : public MouseButtonEvent {
 public:
  MouseButtonReleasedEvent(const ButtonCode aButton)
      : MouseButtonEvent{aButton} {}

  EVENT_TYPE(MouseButtonReleased);
};

}  // namespace EventSystem
}  // namespace Kara