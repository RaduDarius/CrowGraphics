#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/Camera.hpp"
#include "Kara/Layers/Layer.hpp"

#include <glm/glm.hpp>

namespace Kara {
namespace UI {
class MainLayer : public Layers::Layer {
public:
  MainLayer();

  void OnUpdate() override;

private:
  //! Graphics
  Graphics::Camera mCamera;
};
} // namespace UI
} // namespace Kara