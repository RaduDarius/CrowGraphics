#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/UI/Component.hpp"

#include <vector>

namespace Kara {
namespace UI {
class ComponentManager {
public:
  ComponentManager();

  template <class T, typename... Args>
  static Core::Ref<T> CreateComponent(const Rect &aRect, Args... aArgs) {
    auto params = T::Params{std::forward<Args>(args)...};
    return Core::Ref<Component>(aRect, params);
  }

private:
  std::vector<Core::Ref<Component>> mComponents;
};
} // namespace UI
} // namespace Kara