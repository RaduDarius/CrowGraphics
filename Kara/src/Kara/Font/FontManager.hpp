#pragma once

#include <freetype/freetype.h>

namespace Kara {
namespace Font {
class FontManager {
public:
  static void Init();

  static inline FT_Library GetNativeLibrary() { return mFontLibrary; }

private:
  static FT_Library mFontLibrary;
};
} // namespace Font
} // namespace Kara