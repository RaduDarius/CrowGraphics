#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/Camera.hpp"
#include "Kara/Graphics/Renderer.hpp"
#include "Kara/Graphics/Shader.hpp"
#include "Kara/Layers/Layer.hpp"

#include <glm/glm.hpp>

namespace Kara {
namespace UI {
class MainLayer : public Layers::Layer {
public:
  MainLayer();

  void OnUpdate() override;

private:
  struct RenderProps {
    Core::Ref<Graphics::VertexArray> VertexArray;
    glm::vec4 Color{0.0f, 0.0f, 0.0f, 1.0f};
  };

  //! Graphics
  Graphics::Camera mCamera;

  Core::Scope<Graphics::Renderer> mRenderer;
  std::vector<RenderProps> mRenderProps;
  Core::Ref<Graphics::Shader> mShader;
};
} // namespace UI
} // namespace Kara