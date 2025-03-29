#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Types.hpp"
#include "Kara/Font/FontFace.hpp"
#include "Kara/Graphics/ITexture.hpp"
#include "Kara/Graphics/Types.hpp"

#include <string_view>

namespace Kara {
namespace Graphics {
class FontTexture : public ITexture {
public:
  FontTexture(const Font::FontFace &aFontFace) : mFontFace{aFontFace} {}
  virtual ~FontTexture() = default;

  //! FontFace APIs
  void Load(const char aCharacter) { mFontFace.Load(aCharacter); }
  void SetPixelSize(const uint32_t aPixelWidth, const uint32_t aPixelHeight) {
    mFontFace.SetPixelSize(aPixelWidth, aPixelHeight);
  }

  void SetColor(const Graphics::Color &aColor) { mColor = aColor; }
  Graphics::Color GetColor() const { return mColor; }

private:
  Font::FontFace mFontFace;
  Graphics::Color mColor{0.0f, 0.0f, 0.0f, 1.0f};
};

using FontTextureRef = Core::Ref<FontTexture>;
} // namespace Graphics
} // namespace Kara