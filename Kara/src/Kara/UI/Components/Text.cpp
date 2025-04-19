#include "pch.hpp"

#include "Text.hpp"

namespace Kara {
namespace UI {
Text::Text(const ComponentRef aParent, const Rect &aRect, const Params &aParams)
    : Component{aParent, aRect, {}}, mText{aParams.mText},
      mFont{aParams.mFontHandle}, mTextColor{aParams.mTextColor} {}

} // namespace UI
} // namespace Kara