#pragma once

#include "Kara/Core/Core.hpp"
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

  virtual ~Material() {}

  void Bind();

  inline Core::Ref<Shader> GetShader() const { return mShader; }

  void SetColor(const Color &aColor);

private:
  Core::Ref<Shader> mShader;

  std::variant<Color, TextureRef> mData;
};
} // namespace Graphics
} // namespace Kara