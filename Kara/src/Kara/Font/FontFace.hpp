#pragma once

#include "Kara/Font/Types.hpp"

#include <freetype/freetype.h>

namespace Kara {
namespace Font {
class FontFace {
public:
  FontFace(const Handle aHandle);

  inline FT_Face GetNative() const { return mFaceHandle; }
  inline Handle GetHandle() const { return mHandle; }

  void Load(const char aCharacter);

  void SetPixelSize(const uint32_t aPixelWidth, const uint32_t aPixelHeight);

private:
  Handle mHandle;

  // Native data
  FT_Face mFaceHandle;

  uint32_t mPixelWidth{0};
  uint32_t mPixelHeight{0};
};
} // namespace Font
} // namespace Kara