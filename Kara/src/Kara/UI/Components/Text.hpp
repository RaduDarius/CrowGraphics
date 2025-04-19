#pragma once

#include "Kara/Font/FontFace.hpp"
#include "Kara/Font/Types.hpp"
#include "Kara/Graphics/Types.hpp"
#include "Kara/UI/Component.hpp"

#include <string>

namespace Kara {
namespace UI {
class Text : public Component {
public:
  struct Params {
    Params(const std::string &aText, const Font::Handle aFontHandle,
           const Graphics::Color &aTextColor)
        : mText{aText}, mFontHandle{aFontHandle}, mTextColor{aTextColor} {}

    const std::string mText;
    const Font::Handle mFontHandle;
    const Graphics::Color mTextColor;
  };

  Text(const ComponentRef aParent, const Rect &aRect, const Params &aParams);

private:
  std::string mText;
  Font::FontFace mFont;
  Graphics::Color mTextColor;
};
} // namespace UI
} // namespace Kara