#include "pch.hpp"

#include "OpenGlFontTexture.hpp"

#include "Kara/Font/FontManager.hpp"
#include "Kara/Font/Utils.hpp"

#include <glad/glad.h>
#include <stb_image.h>

namespace Kara {
namespace Graphics {
OpenGlFontTexture::OpenGlFontTexture(const Font::FontFace &aFontFace)
    : FontTexture{aFontFace} {
  glGenTextures(1, &mRenderId);
  glBindTexture(GL_TEXTURE_2D, mRenderId);

  const auto bitmap = aFontFace.GetNative()->glyph->bitmap;
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, bitmap.width, bitmap.rows, 0, GL_RED,
               GL_UNSIGNED_BYTE, bitmap.buffer);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

OpenGlFontTexture::~OpenGlFontTexture() { glDeleteTextures(1, &mRenderId); }

void OpenGlFontTexture::Bind() const {
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, mRenderId);
}

void OpenGlFontTexture::Unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

} // namespace Graphics
} // namespace Kara
