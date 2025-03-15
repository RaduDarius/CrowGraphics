#include "pch.hpp"

#include "Desktop.hpp"

#include "Kara/UI/ComponentManager.hpp"

namespace Kara {
namespace UI {
Desktop::Desktop(const ComponentRef aParent, const Rect &aRect,
                 const Params &aParams)
    : Component{aParent, aRect, aParams} {

  const auto component1 = ComponentManager::CreateComponent<Component>(
      std::make_shared<Desktop>(*this), {0, 0, 100, 50});
  component1->SetColor({1.0f, 0.0f, 0.0f, 1.0f});

  const auto component2 = ComponentManager::CreateComponent<Component>(
      std::make_shared<Desktop>(*this), {0, 60, 100, 50});
  component2->SetColor({1.0f, 1.0f, 0.0f, 1.0f});

  const auto component3 = ComponentManager::CreateComponent<Component>(
      std::make_shared<Desktop>(*this), {0, 120, 100, 50});
  component3->SetColor({0.0f, 0.0f, 1.0f, 1.0f});
}

} // namespace UI
} // namespace Kara