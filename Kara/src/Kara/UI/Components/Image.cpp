#include "pch.hpp"

#include "Image.hpp"

#include "Kara/Graphics/Material.hpp"
#include "Kara/Graphics/Renderer.hpp"
#include "Kara/Graphics/Shader.hpp"

namespace Kara {
namespace UI {
Image::Image(const ComponentRef aParent, const Rect &aRect,
             const Params &aParams)
    : Component{aParent, aRect, {}}, mImgHandle{aParams.mImgHandle} {
  SetupRenderPrimitives();
}

void Image::SetupRenderPrimitives() {
  auto texture =
      Graphics::Renderer::CreateTexture(Kara::Image::GetImagePath(mImgHandle));
  SetRenderPropMaterial(std::make_shared<Graphics::Material>(texture));
}

} // namespace UI
} // namespace Kara