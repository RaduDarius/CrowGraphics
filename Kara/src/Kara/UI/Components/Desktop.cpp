#include "pch.hpp"

#include "Desktop.hpp"

#include "Kara/Font/Types.hpp"
#include "Kara/UI/ComponentManager.hpp"
#include "Kara/UI/Components/Image.hpp"
#include "Kara/UI/Components/Text.hpp"

namespace Kara {
namespace UI {
Desktop::Desktop(const ComponentRef aParent, const Rect &aRect,
                 const Params &aParams)
    : Component{aParent, aRect, aParams} {

  // const auto component1 =
  //    ComponentManager::CreateComponent<Component>(Self(), {0, 0, 100, 50});
  // component1->SetColor({1.0f, 0.0f, 0.0f, 1.0f});

  const auto text = ComponentManager::CreateComponent<Text>(
      Self(), {0, 60, 100, 50}, "Ana", Font::Handle::Arial,
      Graphics::Color{0.0f, 0.0f, 0.0f, 1.0f});

  // const auto image = ComponentManager::CreateComponent<Image>(
  //    Self(), {0, 120, 1000, 500}, Kara::Image::Handle::Texture1);
}

} // namespace UI
} // namespace Kara