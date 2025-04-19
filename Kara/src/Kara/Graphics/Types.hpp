#pragma once

#include <glm/glm.hpp>

namespace Kara {
namespace Graphics {
using Color = glm::vec4;

struct Quad {
  glm::vec2 Position;
  glm::vec2 Size;
};
}
} // namespace Kara