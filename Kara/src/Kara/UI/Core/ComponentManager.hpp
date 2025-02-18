#pragma once

#include "Kara/UI/Core/Component.hpp"

#include <vector>

namespace Kara {
namespace UI {
namespace Core {
class ComponentManager {
public:
  ComponentManager();

  void OnUpdate();
  void Render();

private:
  std::vector<Component *> mComponents;
};
} // namespace Core
} // namespace UI
} // namespace Kara