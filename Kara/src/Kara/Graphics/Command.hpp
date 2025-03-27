#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/VertexArray.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Kara {
namespace Graphics {
struct Command {
  static void Init();

  static void Clear(const glm::vec4 &aColor);
  static void Draw(const Core::Ref<VertexArray> &aVertexArray);
};
} // namespace Graphics
} // namespace Kara