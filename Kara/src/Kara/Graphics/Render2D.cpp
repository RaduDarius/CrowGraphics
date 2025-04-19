#include "pch.hpp"

#include "Render2D.hpp"

namespace Kara {
namespace Graphics {
Core::Ref<VertexArray> Render2D::smVertexArray;
Core::Ref<Material> Render2D::smMaterial;

void Render2D::BeginFrame() {}

void Render2D::EndFrame(const glm::mat4 &aVP, const glm::mat4 &aTransform) {
  smMaterial->Bind();
  smMaterial->GetShader()->UploadUniformMat4("uVP", aVP);
  smMaterial->GetShader()->UploadUniformMat4("uModel", aTransform);

  smVertexArray->Bind();
  Graphics::RenderCommand::Draw(smVertexArray);
}

void Render2D::SubmitQuad(const Core::Ref<VertexArray> &aVertexArray,
                          const Core::Ref<Material> &aMaterial) {
  smVertexArray = aVertexArray;
  smMaterial = aMaterial;
}

} // namespace Graphics
} // namespace Kara