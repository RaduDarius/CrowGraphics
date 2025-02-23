#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Layers/Layer.hpp"

namespace Kara {
namespace UI {
class UILayer : public Layers::Layer {
public:
  UILayer();

  void OnAttach() override;
  void OnDetach() override;
  void OnRender() override;

  void Begin();
  void End();

private:
  float mTime{0.0f};
};
} // namespace UI
} // namespace Kara