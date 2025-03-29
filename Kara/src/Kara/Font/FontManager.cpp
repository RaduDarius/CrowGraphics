#include "pch.hpp"

#include "FontManager.hpp"

namespace Kara {
namespace Font {
FT_Library FontManager::mFontLibrary;

void FontManager::Init() { FT_Init_FreeType(&mFontLibrary); }

} // namespace Font
} // namespace Kara