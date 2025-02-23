#pragma once

#include "Kara/Events/Event.hpp"

namespace Kara {
namespace Events {
class Dispatcher {
  template <typename T> using EventFunc = std::function<bool(T &)>;

public:
  Dispatcher(Event &aEvent) : mEvent{aEvent} {}

  template <typename T> bool Dispatch(const EventFunc<T> &aCallback) {
    if (mEvent.GetType() == T::GetStaticType()) {
      mEvent.mIsHandled = aCallback(*reinterpret_cast<T *>(&mEvent));
      return true;
    }
    return false;
  }

private:
  Event &mEvent;
};
} // namespace Events
} // namespace Kara