#pragma

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/Material.hpp"
#include "Kara/Graphics/RenderBatcher2D.hpp"
#include "Kara/Graphics/RenderCommand.hpp"
#include "Kara/Graphics/VertexArray.hpp"

#include "glm/glm.hpp"

namespace Kara {
namespace Graphics {
class Render2D {
public:
  static void Init() { RenderCommand::Init(); }
  static void Clear() { RenderCommand::Clear({1.0f, 0.0f, 1.0f, 1.0f}); }

  static void BeginFrame();
  static void EndFrame(const glm::mat4 &aVP,
                       const glm::mat4 &aTransform = glm::mat4(1.0f));

  static void SubmitQuad(const Quad &aQuad,
                         const Core::Ref<Material> &aMaterial) {
    smBatcher.SubmitQuad(aQuad, aMaterial);
  }

private:
  static RenderBatcher2D smBatcher;
};
} // namespace Graphics
} // namespace Kara