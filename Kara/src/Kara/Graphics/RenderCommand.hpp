#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/VertexArray.hpp"
#include "Kara/Graphics/Types.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Kara {
namespace Graphics {
struct RenderCommand {
  static void Init();

  static void Clear(const Color &aColor);
  static void Draw(const Core::Ref<VertexArray> &aVertexArray);
};
} // namespace Graphics
} // namespace Kara