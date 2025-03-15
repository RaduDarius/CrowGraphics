#pragma once

#include "Kara/Graphics/VertexBuffer.hpp"

#include <glm/glm.hpp>

#include <vector>

namespace Kara {
namespace UI {
struct RenderObject {
  std::vector<float> Vertices;
  std::vector<uint32_t> Indeces;
  glm::vec4 Color{1.0f, 1.0f, 1.0f, 1.0f};

  Graphics::BufferLayout Layout{};
};
} // namespace UI
} // namespace Kara