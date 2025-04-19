#pragma once

#include "Kara/Graphics/Camera.hpp"
#include "Kara/Layers/Layer.hpp"

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