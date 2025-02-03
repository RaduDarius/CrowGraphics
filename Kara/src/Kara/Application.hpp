#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Window.hpp"
#include "Kara/LayerSystem/LayerStack.hpp"

namespace Kara {
namespace EventSystem {
class Event;
class WindowClosedEvent;
} // namespace EventSystem

namespace LayerSystem {
class Layer;
} // namespace LayerSystem

class KARA_API Application {
public:
  Application();

  void Run();

  void OnEvent(EventSystem::Event &aEvent);

  void Push(LayerSystem::Layer *aLayer);
  void Pop(LayerSystem::Layer *aLayer);

private:
  bool OnClose(EventSystem::WindowClosedEvent &aEvent);

  std::unique_ptr<Core::Window> mWindow;
  std::unique_ptr<LayerSystem::LayerStack> mLayerStack;

  bool mRunning{true};
};

Application *CreateApplication();
} // namespace Kara
