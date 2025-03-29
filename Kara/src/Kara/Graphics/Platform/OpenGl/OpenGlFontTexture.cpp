#include "pch.hpp"

#include "OpenGlFontTexture.hpp"

#include "Kara/Font/FontFace.hpp"
#include "Kara/Font/FontManager.hpp"
#include "Kara/Font/Utils.hpp"

#include <glad/glad.h>
#include <stb_image.h>

namespace Kara {
namespace Graphics {
namespace {
const std::string SupportedCharsMap{
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "};
}

OpenGlFontTexture::OpenGlFontTexture(const Font::FontFace &aFontFace)
    : FontTexture{aFontFace} {
  glGenTextures(1, &mRenderId);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, mRenderId);

  static constexpr float AtlasWidth{512};
  static constexpr float AtlasHeight{512};

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, static_cast<GLsizei>(AtlasWidth),
               static_cast<GLsizei>(AtlasHeight), 0, GL_RED, GL_UNSIGNED_BYTE,
               nullptr);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  const auto &nativeFont = aFontFace.GetNative();

  int penX = 0;
  int penY = 0;
  unsigned int rowHeight = 0;

  for (const auto &character : SupportedCharsMap) {
    if (FT_Load_Char(nativeFont, character, FT_LOAD_RENDER))
      continue;

    const auto &bmp = nativeFont->glyph->bitmap;

    // Wrap to next row if needed
    if (penX + bmp.width >= AtlasWidth) {
      penX = 0;
      penY += rowHeight;
      rowHeight = 0;
    }

    // Upload glyph into atlas
    glTexSubImage2D(GL_TEXTURE_2D, 0, penX, penY, bmp.width, bmp.rows, GL_RED,
                    GL_UNSIGNED_BYTE, bmp.buffer);

    // Save glyph info
    Font::Glyph info;
    info.UvOffset = glm::vec2(penX / AtlasWidth, penY / AtlasHeight);
    info.UvSize = glm::vec2(bmp.width / AtlasWidth, bmp.rows / AtlasHeight);
    info.Size = {bmp.width, bmp.rows};
    info.Bearing = {nativeFont->glyph->bitmap_left,
                    nativeFont->glyph->bitmap_top};
    info.Advance = nativeFont->glyph->advance.x >> 6;

    SetGlyph(character, info);

    penX += bmp.width;
    rowHeight = std::max(rowHeight, bmp.rows);
  }
}

OpenGlFontTexture::~OpenGlFontTexture() { glDeleteTextures(1, &mRenderId); }

void OpenGlFontTexture::Bind() const {
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, mRenderId);
}

void OpenGlFontTexture::Unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

} // namespace Graphics
} // namespace Kara
