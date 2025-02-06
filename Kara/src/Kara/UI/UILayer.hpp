#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/LayerSystem/Layer.hpp"
#include "Kara/UI/EventHandler.hpp"

namespace Kara {
namespace UI {
class KARA_API UILayer : public LayerSystem::Layer {
public:
  UILayer();
  ~UILayer();

  virtual void OnAttach() override;
  virtual void OnDetach() override;
  virtual void OnRender() override;

  void Begin();
  void End();

private:
  EventHandler mEventHandler;

  float mTime{0.0f};
};
} // namespace UI
} // namespace Kara