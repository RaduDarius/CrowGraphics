#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Render/Renderer.hpp"
#include "Kara/Core/Window.hpp"
#include "Kara/LayerSystem/LayerStack.hpp"
#include "Kara/UI/UILayer.hpp"

namespace Kara {
namespace EventSystem {
class Event;
class WindowClosedEvent;
} // namespace EventSystem

namespace LayerSystem {
class Layer;
} // namespace LayerSystem

class Application {
public:
  Application();

  void Run();

  static Application *Get() { return smInstance; }

  Core::Window *GetWindow() const { return mWindow.get(); }
  CoreTypes::Size GetWindowSize() const { return mWindow->GetSize(); }

  void OnEvent(EventSystem::Event &aEvent);

  void Push(LayerSystem::Layer *aLayer);
  void Pop(LayerSystem::Layer *aLayer);

private:
  bool OnClose(EventSystem::WindowClosedEvent &aEvent);

  std::unique_ptr<Core::Render::Renderer> mRenderer;
  std::unique_ptr<Core::Window> mWindow;
  UI::UILayer *mUILayer{nullptr};

  LayerSystem::LayerStack mLayerStack;

  bool mRunning{true};

  static Application *smInstance;
};

Application *CreateApplication();
} // namespace Kara
