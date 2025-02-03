#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/LayerSystem/Layer.hpp"
#include "Kara/UI/EventHandler.hpp"

namespace Kara {
namespace UI {
class KARA_API UILayer : public LayerSystem::Layer {
public:
  UILayer();
  ~UILayer();

  void OnAttach();
  void OnDetach();
  void OnUpdate();
  void OnEvent(EventSystem::Event &aEvent);

private:
  //! @brief Override the mTime with the (currentTime) receved from the glfw
  //! module
  //! @return The delta time which will be mTime - currentTime
  float GetDeltaTime();

  EventHandler mEventHandler;

  float mTime{0.0f};
};
} // namespace UI
} // namespace Kara