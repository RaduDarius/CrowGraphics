#include "pch.hpp"

#include "Image.hpp"

#include "Kara/Graphics/Renderer.hpp"

namespace Kara {
namespace UI {
Image::Image(const ComponentRef aParent, const Rect &aRect,
             const Params &aParams)
    : Component{aParent, aRect, {}}, mImgHandle{aParams.mImgHandle} {
  SetupRenderPrimitives();
}

void Image::SetupRenderPrimitives() {
  SetRenderPropMaterial(
      std::make_shared<Graphics::Material>(Graphics::Renderer::CreateTexture(
          Kara::Image::GetImagePath(mImgHandle))));
}

} // namespace UI
} // namespace Kara