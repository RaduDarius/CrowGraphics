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

  Rect rect{0, 0, 100, 150};
  const auto component1 =
      ComponentManager::CreateComponent<Component>(Self(), rect);
  component1->SetColor({1.0f, 0.0f, 0.0f, 1.0f});

  rect.Y += rect.Height;
  const auto text = ComponentManager::CreateComponent<Text>(
      Self(), rect, "Hello Goby", Font::Handle::Arial,
      Graphics::Color{1.0f, 0.0f, 0.0f, 1.0f});

  rect.Y += rect.Height;
  const auto image = ComponentManager::CreateComponent<Image>(
      Self(), rect, Kara::Image::Handle::Texture1);
}

} // namespace UI
} // namespace Kara