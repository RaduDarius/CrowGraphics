#pragma once

#include "Kara/EventSystem/Event.hpp"

namespace Kara {
namespace EventSystem {
class EventDispatcher {
  template <typename T>
  using EventFunc = std::function<bool(T&)>;

 public:
  EventDispatcher(const Event& aEvent) : mEvent{aEvent} {}

  template <typename T>
  bool Dispatch(EventFunc<T>& aCallback) {
    if (mEvent.GetType() == T::GetStaticType()) {
      mEvent.mIsHandled = aCallback(*(T*)&mEvent);
      return true;
    }
    return false;
  }

 private:
  const Event& mEvent;
};
}  // namespace EventSystem
}  // namespace Kara