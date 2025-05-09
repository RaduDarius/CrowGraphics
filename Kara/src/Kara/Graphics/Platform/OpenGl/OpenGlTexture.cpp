#include "pch.hpp"

#include "OpenGlTexture.hpp"

#include <glad/glad.h>
#include <stb_image.h>

namespace Kara {
namespace Graphics {
OpenGlTexture::OpenGlTexture(const std::string_view &aPath) : Texture{aPath} {
  glGenTextures(1, &mRenderId);
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, mRenderId);

  int width, height, nrChannels;
  unsigned char *data =
      stbi_load(aPath.data(), &width, &height, &nrChannels, 4);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

OpenGlTexture::~OpenGlTexture() { glDeleteTextures(1, &mRenderId); }

void OpenGlTexture::Bind() const {
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, mRenderId);
}

void OpenGlTexture::Unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

} // namespace Graphics
} // namespace Kara
