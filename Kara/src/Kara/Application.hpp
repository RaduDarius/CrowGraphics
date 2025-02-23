#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Window.hpp"
#include "Kara/Layers/LayerStack.hpp"
#include "Kara/UI/UILayer.hpp"

namespace Kara {
namespace Events {
class Event;
class WindowClosedEvent;
} // namespace Events

namespace Layers {
class Layer;
} // namespace Layers

class Application {
public:
  Application();

  void Run();

  static Application *Get() { return smInstance; }

  Core::Window *GetWindow() const { return mWindow.get(); }
  CoreTypes::Size GetWindowSize() const { return mWindow->GetSize(); }

  void OnEvent(Events::Event &aEvent);

  void Push(Layers::Layer *aLayer);
  void Pop(Layers::Layer *aLayer);

private:
  bool OnClose(Events::WindowClosedEvent &aEvent);

  // Components
  Core::Scope<Core::Window> mWindow;
  UI::UILayer *mUILayer{nullptr};
  Layers::LayerStack mLayerStack;

  // Data
  bool mRunning{true};

  // Instance
  static Application *smInstance;
};

Application *CreateApplication();
} // namespace Kara
