#pragma once

#include "Kara/EventSystem/Event.hpp"
#include "Kara/LayerSystem/Layer.hpp"
#include "Kara/UI/Core/ComponentManager.hpp"

#include <memory>

namespace Kara {
namespace UI {
class MainLayer : public LayerSystem::Layer {
public:
  MainLayer();

  void OnAttach() override;
  void OnEvent(EventSystem::Event &aEvent) override;
  void OnRender() override;

private:
  std::unique_ptr<UI::Core::ComponentManager> mComponentManager;
};
} // namespace UI
} // namespace Kara