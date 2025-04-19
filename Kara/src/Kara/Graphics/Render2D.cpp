#include "pch.hpp"

#include "Render2D.hpp"

namespace Kara {
namespace Graphics {
RenderBatcher2D Render2D::smBatcher;

void Render2D::BeginFrame() { smBatcher.Clear(); }

void Render2D::EndFrame(const glm::mat4 &aVP, const glm::mat4 &aTransform) {
  for (const auto &[material, vertexArrays] : smBatcher.GetBatches()) {
    material->Bind();
    material->GetShader()->UploadUniformMat4("uVP", aVP);
    material->GetShader()->UploadUniformMat4("uModel", aTransform);

    for (const auto &vertexArray : vertexArrays) {
      vertexArray->Bind();
      Graphics::RenderCommand::Draw(vertexArray);
      vertexArray->Unbind();
    }
    material->Unbind();
  }
}

} // namespace Graphics
} // namespace Kara