#include "pch.hpp"

#include "Desktop.hpp"

#include "Kara/UI/ComponentManager.hpp"
#include "Kara/UI/Components/Image.hpp"

namespace Kara {
namespace UI {
Desktop::Desktop(const ComponentRef aParent, const Rect &aRect,
                 const Params &aParams)
    : Component{aParent, aRect, aParams} {

  const auto component1 =
      ComponentManager::CreateComponent<Component>(Self(), {0, 0, 100, 50});
  component1->SetColor({1.0f, 0.0f, 0.0f, 1.0f});

  const auto component2 =
      ComponentManager::CreateComponent<Component>(Self(), {0, 60, 100, 50});
  component2->SetColor({1.0f, 1.0f, 0.0f, 1.0f});

  const auto image = ComponentManager::CreateComponent<Image>(
      Self(), {0, 120, 1000, 500}, Kara::Image::Handle::Texture1);
}

} // namespace UI
} // namespace Kara