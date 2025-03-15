#include "pch.hpp"

#include "Desktop.hpp"

#include "Kara/UI/ComponentManager.hpp"

namespace Kara {
namespace UI {
Desktop::Desktop(const ComponentRef aParent, const Rect &aRect,
                 const Params &aParams)
    : Component{aParent, aRect, aParams} {

  ComponentManager::CreateComponent<Component>(std::make_shared<Desktop>(*this),
                                               {0, 0, 100, 50});

  ComponentManager::CreateComponent<Component>(std::make_shared<Desktop>(*this),
                                               {0, 60, 100, 50});

  ComponentManager::CreateComponent<Component>(std::make_shared<Desktop>(*this),
                                               {0, 120, 100, 50});
}

} // namespace UI
} // namespace Kara