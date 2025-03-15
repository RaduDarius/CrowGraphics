#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/VertexArray.hpp"
#include "Kara/Graphics/VertexBuffer.hpp"

#include <glm/glm.hpp>

#include <vector>

namespace Kara {
namespace UI {
struct RenderObject {
  std::vector<float> Vertices;
  std::vector<uint32_t> Indeces;
  Core::Ref<Graphics::VertexArray> VertexArray;

  glm::vec4 Color{1.0f, 1.0f, 1.0f, 1.0f};
};
} // namespace UI
} // namespace Kara