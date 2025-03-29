#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Types.hpp"
#include "Kara/Font/FontFace.hpp"
#include "Kara/Font/Types.hpp"
#include "Kara/Graphics/ITexture.hpp"
#include "Kara/Graphics/Types.hpp"

#include <string_view>
#include <unordered_map>

namespace Kara {
namespace Graphics {
class FontTexture : public ITexture {
public:
  FontTexture(const Font::FontFace &aFontFace) : mFontFace{aFontFace} {}
  virtual ~FontTexture() = default;

  //! FontFace APIs
  inline void Load(const char aCharacter) { mFontFace.Load(aCharacter); }

  inline uint32_t GetFontHeight() const { return mFontFace.GetPixelHeight(); }
  inline void SetPixelSize(const uint32_t aPixelWidth,
                           const uint32_t aPixelHeight) {
    mFontFace.SetPixelSize(aPixelWidth, aPixelHeight);
  }

  inline void SetColor(const Graphics::Color &aColor) { mColor = aColor; }
  inline Graphics::Color GetColor() const { return mColor; }

  inline const std::unordered_map<char, Font::Glyph> &GetGlyphs() const {
    return mGlyphs;
  }
  inline void SetGlyph(const char aChar, const Font::Glyph &aGlyph) {
    mGlyphs[aChar] = aGlyph;
  }

private:
  Font::FontFace mFontFace;
  Graphics::Color mColor{0.0f, 0.0f, 0.0f, 1.0f};

  std::unordered_map<char, Font::Glyph> mGlyphs;
};

using FontTextureRef = Core::Ref<FontTexture>;
} // namespace Graphics
} // namespace Kara