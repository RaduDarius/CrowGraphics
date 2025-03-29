#include "pch.hpp"

#include "Text.hpp"

#include "Kara/Graphics/Material.hpp"
#include "Kara/Graphics/Renderer.hpp"
#include "Kara/Graphics/Shader.hpp"

namespace Kara {
namespace UI {
Text::Text(const ComponentRef aParent, const Rect &aRect, const Params &aParams)
    : Component{aParent, aRect, {}}, mText{aParams.mText},
      mFont{aParams.mFontHandle} {
  SetupRenderPrimitives();
}

void Text::SetupRenderPrimitives() {
  const auto size = GetSize();
  mFont.SetPixelSize(size.Width, size.Height);
  mFont.Load('A');

  const auto texture = Graphics::Renderer::CreateFontTexture(mFont);
  SetRenderPropMaterial(std::make_shared<Graphics::Material>(texture));
}

} // namespace UI
} // namespace Kara