#include "pch.hpp"

#include "Material.hpp"

#include "Kara/Graphics/Renderer.hpp"

namespace Kara {
namespace Graphics {
Material::Material(const Color &aColor)
    : mShader{Renderer::CreateShader(Shader::Type::Basic)}, mData{aColor} {}

Material::Material(const TextureRef aTexture)
    : mShader{Renderer::CreateShader(Shader::Type::Texture)}, mData{aTexture} {}

Material::Material(const FontTextureRef aTexture)
    : mShader{Renderer::CreateShader(Shader::Type::Font)}, mData{aTexture} {}

void Material::Bind() {
  if (std::holds_alternative<TextureRef>(mData)) {
    std::get<TextureRef>(mData)->Bind();
    mShader->Bind();
    mShader->UploadUniformInt("uTexture", 1);
  } else if (std::holds_alternative<FontTextureRef>(mData)) {
    const auto texture = std::get<FontTextureRef>(mData);
    texture->Bind();
    mShader->Bind();
    mShader->UploadUniformInt("uTexture", 0);
    mShader->UploadUniformVec4("uTextColor", texture->GetColor());
  } else if (std::holds_alternative<Color>(mData)) {
    mShader->Bind();
    mShader->UploadUniformVec4("uColor", std::get<Color>(mData));
  }
}

void Material::Unbind() {
  if (std::holds_alternative<TextureRef>(mData)) {
    std::get<TextureRef>(mData)->Unbind();
  } else if (std::holds_alternative<FontTextureRef>(mData)) {
    std::get<FontTextureRef>(mData)->Unbind();
  }
  mShader->Unbind();
}

void Material::SetFontColor(const Color &aColor) {
  if (std::holds_alternative<FontTextureRef>(mData)) {
    const auto texture = std::get<FontTextureRef>(mData);
    texture->SetColor(aColor);
    mShader->UploadUniformVec4("uTextColor", texture->GetColor());
  }
}

void Material::SetColor(const Color &aColor) {
  if (std::holds_alternative<Color>(mData)) {
    mData = aColor;
    mShader->UploadUniformVec4("uColor", aColor);
  }
}

void Material::MakeTransparent() {
  if (std::holds_alternative<Color>(mData)) {
    auto& color = std::get<Color>(mData);
    color.a = .0f;
    mShader->UploadUniformVec4("uColor", color);
  }
}

} // namespace Graphics
} // namespace Kara