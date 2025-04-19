#include "pch.hpp"

#include "Image.hpp"

namespace Kara {
namespace UI {
Image::Image(const ComponentRef aParent, const Rect &aRect,
             const Params &aParams)
    : Component{aParent, aRect, {}}, mImgHandle{aParams.mImgHandle} {}

} // namespace UI
} // namespace Kara