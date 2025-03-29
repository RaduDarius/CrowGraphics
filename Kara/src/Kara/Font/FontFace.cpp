#include "pch.hpp"

#include "FontFace.hpp"

#include "Kara/Font/FontManager.hpp"
#include "Kara/Font/Utils.hpp"

namespace Kara {
namespace Font {
FontFace::FontFace(const Handle aHandle) : mHandle{aHandle} {
  FT_New_Face(FontManager::GetNativeLibrary(), GetFaceTypePath(mHandle).data(),
              0, &mFaceHandle);
}

void FontFace::Load(const char aCharacter) {
  FT_Load_Char(mFaceHandle, aCharacter, FT_LOAD_RENDER);
}

void FontFace::SetPixelSize(const uint32_t aPixelWidth,
                            const uint32_t aPixelHeight) {
  mPixelWidth = aPixelWidth;
  mPixelHeight = aPixelHeight;

  FT_Set_Pixel_Sizes(mFaceHandle, mPixelWidth, mPixelHeight);
}

} // namespace Font
} // namespace Kara