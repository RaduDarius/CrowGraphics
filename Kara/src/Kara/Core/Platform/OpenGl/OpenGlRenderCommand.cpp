#include "pch.hpp"

#include "Kara/Core/Render/Command.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Kara {
namespace Core {
namespace Render {
void Command::Clear(const glm::vec4 &aColor) {
  glClearColor(aColor.r, aColor.g, aColor.b, aColor.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Command::Draw(const std::shared_ptr<VertexArray> &aVertexArray) {
  glDrawElements(GL_TRIANGLES, aVertexArray->GetIndexBuffer()->Count(),
                 GL_UNSIGNED_INT, nullptr);
}

} // namespace Render
} // namespace Core
} // namespace Kara