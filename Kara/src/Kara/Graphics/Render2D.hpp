#pragma

#include "Kara/Graphics/RenderCommand.hpp"

namespace Kara {
namespace Graphics {
class Render2D {
public:
  static void Init() { RenderCommand::Init(); }
  static void Clear() { RenderCommand::Clear({1.0f, 0.0f, 1.0f, 1.0f}); }
};
} // namespace Graphics
} // namespace Kara