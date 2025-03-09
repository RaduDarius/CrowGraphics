#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/UI/Component.hpp"

#include <vector>

namespace Kara {
namespace UI {
class ComponentManager {
public:
  ComponentManager();

private:
  std::vector<Core::Ref<Component>> mComponents;
};
} // namespace UI
} // namespace Kara