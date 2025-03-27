#include "pch.hpp"

#include "Material.hpp"

#include "Kara/Graphics/Renderer.hpp"

namespace Kara {
namespace Graphics {
Material::Material(const Color &aColor)
    : mShader{Renderer::CreateShader(Shader::Type::Basic)}, mData{aColor} {}

Material::Material(const TextureRef aTexture)
    : mShader{Renderer::CreateShader(Shader::Type::Texture)}, mData{aTexture} {}

void Material::Bind() {
  if (std::holds_alternative<TextureRef>(mData)) {
    std::get<TextureRef>(mData)->Bind();
    mShader->Bind();
    mShader->UploadUniformInt("uTexture", 1);
  } else if (std::holds_alternative<Color>(mData)) {
    mShader->Bind();
    mShader->UploadUniformVec4("uColor", std::get<Color>(mData));
  }
}

void Material::SetColor(const Color &aColor) {
  if (std::holds_alternative<Color>(mData)) {
    mData = aColor;
    mShader->UploadUniformVec4("uColor", aColor);
  }
}

} // namespace Graphics
} // namespace Kara