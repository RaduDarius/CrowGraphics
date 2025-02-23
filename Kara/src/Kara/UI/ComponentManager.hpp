#pragma once

#include "Kara/UI/Component.hpp"

#include <vector>

namespace Kara {
namespace UI {
class ComponentManager {
public:
  ComponentManager();

  void OnUpdate();
  void Render();

private:
  std::vector<Component *> mComponents;
};
} // namespace UI
} // namespace Kara