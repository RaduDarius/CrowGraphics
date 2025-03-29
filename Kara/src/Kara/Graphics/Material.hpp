#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/FontTexture.hpp"
#include "Kara/Graphics/Shader.hpp"
#include "Kara/Graphics/Texture.hpp"
#include "Kara/Graphics/Types.hpp"

#include <variant>

namespace Kara {
namespace Graphics {
class Material {
public:
  Material(const Color &aColor);
  Material(const TextureRef aTexture);
  Material(const FontTextureRef aTexture);

  virtual ~Material() = default;

  void Bind();
  void Unbind();

  inline Core::Ref<Shader> GetShader() const { return mShader; }

  void SetFontColor(const Color &aColor);
  void SetColor(const Color &aColor);

private:
  Core::Ref<Shader> mShader;

  std::variant<Color, TextureRef, FontTextureRef> mData;
};
} // namespace Graphics
} // namespace Kara