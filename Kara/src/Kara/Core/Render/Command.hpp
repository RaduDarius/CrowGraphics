#pragma once

#include "Kara/Core/Render/VertexArray.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Kara {
namespace Core {
namespace Render {
struct Command {
  static void Clear(const glm::vec4 &aColor);
  static void Draw(const std::shared_ptr<VertexArray> &aVertexArray);
};
} // namespace Render
} // namespace Core
} // namespace Kara