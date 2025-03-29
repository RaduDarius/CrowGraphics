#pragma once

#include "Kara/Core/Types.hpp"
#include "Kara/Font/Types.hpp"
#include "Kara/Graphics/FontTexture.hpp"

namespace Kara {
namespace Font {
class FontFace;
}
namespace Graphics {
class OpenGlFontTexture : public FontTexture {
public:
  OpenGlFontTexture(const Font::FontFace &aFontFace);
  ~OpenGlFontTexture() override;

  void Bind() const override;
  void Unbind() const override;

private:
  unsigned int mRenderId;
};
} // namespace Graphics
} // namespace Kara
