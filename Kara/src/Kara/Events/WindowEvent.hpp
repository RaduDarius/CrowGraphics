#pragma once

#include "Kara/Core/Types.hpp"
#include "Kara/Events/Event.hpp"

namespace Kara {
namespace Events {
//! Events that are specific to a WINDOW:
//! WindowClose, WindowResize, WindowMoved.

class WindowResizedEvent : public Event {
public:
  using Size = Point;

  WindowResizedEvent(const float aWidth, const float aHeight)
      : mSize{aWidth, aHeight} {}
  WindowResizedEvent(const Size &aSize) : mSize{aSize} {}

  inline Size GetSize() { return mSize; }
  inline float GetWidth() { return mSize.x; }
  inline float GetHeight() { return mSize.y; }

  inline std::string ToString() const override {
    std::stringstream ss;
    ss << GetName() << ": " << mSize << '\n';
    return ss.str();
  }

  EVENT_TYPE(WindowResized);

private:
  Size mSize;
};

class WindowMovedEvent : public Event {
public:
  using Position = Point;

  WindowMovedEvent(const float aX, const float aY) : mPosition{aX, aY} {}
  WindowMovedEvent(const Position &aPosition) : mPosition{aPosition} {}

  inline Position GetPosition() { return mPosition; }
  inline float GetXOffset() { return mPosition.x; }
  inline float GetYOffset() { return mPosition.y; }

  inline std::string ToString() const override {
    std::stringstream ss;
    ss << GetName() << ": " << mPosition << '\n';
    return ss.str();
  }

  EVENT_TYPE(WindowMoved);

private:
  Position mPosition;
};

class WindowClosedEvent : public Event {
public:
  inline std::string ToString() const override { return GetName(); }

  EVENT_TYPE(WindowClosed);
};

} // namespace Events
} // namespace Kara