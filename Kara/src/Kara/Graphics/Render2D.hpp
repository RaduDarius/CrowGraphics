#pragma

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/Material.hpp"
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
  static void EndFrame(const glm::mat4 &aVP, const glm::mat4 &aTransform);

  static void SubmitQuad(const Core::Ref<VertexArray> &aVertexArray,
                         const Core::Ref<Material> &aMaterial);

private:
  static Core::Ref<VertexArray> smVertexArray;
  static Core::Ref<Material> smMaterial;
};
} // namespace Graphics
} // namespace Kara