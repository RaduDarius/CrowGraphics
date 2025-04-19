#pragma once

#include "Kara/UI/Component.hpp"
#include "Kara/UI/Utils.hpp"

#include "Kara/Image/Types.hpp"

namespace Kara {
namespace UI {
class Image : public Component {
public:
  struct Params {
    Params(const Kara::Image::Handle aImgHandle) : mImgHandle{aImgHandle} {}

    const Kara::Image::Handle mImgHandle;
  };

  Image(const ComponentRef aParent, const Rect &aRect, const Params &aParams);

private:
  Kara::Image::Handle mImgHandle{Kara::Image::Handle::None};
};
} // namespace UI
} // namespace Kara