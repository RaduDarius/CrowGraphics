#include "pch.hpp"

#include "RenderBatcher2D.hpp"

#include "Kara/Graphics/Renderer.hpp"

namespace Kara {
namespace Graphics {
void RenderBatcher2D::SubmitQuad(const Quad &aQuad,
                                 const Core::Ref<Material> aMaterial) {
  mBatches[aMaterial].push_back(ConstructVertexArray(aQuad));
}

Core::Ref<VertexArray>
RenderBatcher2D::ConstructVertexArray(const Quad &aQuad) const {
  auto vertexArray = Renderer::CreateVertexArray();

  float vertices[]{
      aQuad.Position.x,
      aQuad.Position.y,
      0.f,
      aQuad.Position.x + aQuad.Size.x,
      aQuad.Position.y,
      0.f,
      aQuad.Position.x + aQuad.Size.x,
      aQuad.Position.y + aQuad.Size.y,
      0.f,
      aQuad.Position.x,
      aQuad.Position.y + aQuad.Size.y,
      0.f,
  };
  const auto vertexBuffer =
      Graphics::Renderer::CreateVertexBuffer(vertices, sizeof(vertices));
  vertexBuffer->SetLayout({
      {Graphics::BufferElementType::Float3, "inPosition"},
  });
  vertexArray->AddVertexBuffer(vertexBuffer);

  uint32_t indices[]{0, 1, 2, 2, 3, 0};
  auto indexBuffer =
      Graphics::Renderer::CreateIndexBuffer(indices, sizeof(indices));
  vertexArray->AddIndexBuffer(indexBuffer);

  return vertexArray;
}
} // namespace Graphics
} // namespace Kara