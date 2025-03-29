#include "pch.hpp"

#include "Text.hpp"

#include "Kara/Graphics/Material.hpp"
#include "Kara/Graphics/Renderer.hpp"
#include "Kara/Graphics/Shader.hpp"

namespace Kara {
namespace UI {
Text::Text(const ComponentRef aParent, const Rect &aRect, const Params &aParams)
    : Component{aParent, aRect, {}}, mText{aParams.mText},
      mFont{aParams.mFontHandle} {
  SetupRenderPrimitives();
}

void Text::SetupRenderPrimitives() {
  mRenderProp = std::make_shared<RenderObject>();

  mFont.SetPixelSize(0, 64);
  const auto texture = Graphics::Renderer::CreateFontTexture(mFont);
  const auto fontHeight = texture->GetFontHeight();
  auto glyphs = texture->GetGlyphs();

  const auto rect = GetRect();
  float cursorX = static_cast<float>(rect.X);
  uint32_t vertexOffset{0};

  std::vector<float> vertices;
  std::vector<uint32_t> indeces;

  for (const auto &c : mText) {
    const auto &glyph = glyphs[c];

    const float x = cursorX + glyph.Bearing.x;
    const float y = rect.Y + (static_cast<float>(fontHeight) - glyph.Bearing.y);
    const auto width = glyph.Size.x;
    const auto height = glyph.Size.y;

    float u0 = glyph.UvOffset.x;
    float v0 = glyph.UvOffset.y;
    float u1 = u0 + glyph.UvSize.x;
    float v1 = v0 + glyph.UvSize.y;

    mRenderProp->Vertices.insert(mRenderProp->Vertices.end(),
                                 {x,         y,          0.0f, u0, v0,
                                  x + width, y,          0.0f, u1, v0,
                                  x + width, y + height, 0.0f, u1, v1,
                                  x,         y + height, 0.0f, u0, v1});

    mRenderProp->Indeces.insert(mRenderProp->Indeces.end(),
                                {vertexOffset + 0, vertexOffset + 1,
                                 vertexOffset + 2, vertexOffset + 2,
                                 vertexOffset + 3, vertexOffset + 0});
    vertexOffset += 4;
    cursorX += glyph.Advance;
  }

  mRenderProp->VertexArray = Graphics::Renderer::CreateVertexArray();

  const auto vertexBuffer = Graphics::Renderer::CreateVertexBuffer(
      mRenderProp->Vertices.data(),
      mRenderProp->Vertices.size() * sizeof(float));

  vertexBuffer->SetLayout({
      {Graphics::BufferElementType::Float3, "inPosition"},
      {Graphics::BufferElementType::Float2, "inTextCoord"},
  });

  mRenderProp->VertexArray->AddVertexBuffer(vertexBuffer);

  auto indexBuffer = Graphics::Renderer::CreateIndexBuffer(
      mRenderProp->Indeces.data(),
      mRenderProp->Indeces.size() * sizeof(uint32_t));
  mRenderProp->VertexArray->AddIndexBuffer(indexBuffer);

  mRenderProp->Material = std::make_shared<Graphics::Material>(texture);
}

} // namespace UI
} // namespace Kara