#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/LayerSystem/Layer.hpp"

namespace Kara {
namespace UI {
class UILayer : public LayerSystem::Layer {
public:
  UILayer();
  ~UILayer();

  virtual void OnAttach() override;
  virtual void OnDetach() override;
  virtual void OnRender() override;

  void Begin();
  void End();

private:
  float mTime{0.0f};
};
} // namespace UI
} // namespace Kara