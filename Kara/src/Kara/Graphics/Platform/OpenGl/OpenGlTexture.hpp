#pragma once

#include "Kara/Graphics/Texture.hpp"

namespace Kara {
namespace Graphics {
class OpenGlTexture : public Texture {
public:
  OpenGlTexture(const std::string_view &aPath);
  ~OpenGlTexture() override;

  void Bind() const override;
  void Unbind() const override;

private:
  unsigned int mRenderId;
};
} // namespace Graphics
} // namespace Kara
