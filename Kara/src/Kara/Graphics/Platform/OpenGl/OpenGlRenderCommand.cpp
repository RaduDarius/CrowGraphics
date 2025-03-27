#include "pch.hpp"

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/Command.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Kara {
namespace Graphics {
void Command::Init() {
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);
}

void Command::Clear(const glm::vec4 &aColor) {
  glClearColor(aColor.r, aColor.g, aColor.b, aColor.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Command::Draw(const Core::Ref<VertexArray> &aVertexArray) {
  auto indexBuffer = aVertexArray->GetIndexBuffer();
  const auto count = indexBuffer ? indexBuffer->Count() : 0;
  glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}

} // namespace Graphics
} // namespace Kara