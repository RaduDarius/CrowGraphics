#include "pch.hpp"

#include "Application.hpp"

#include "Kara/Events/Dispatcher.hpp"
#include "Kara/Events/Event.hpp"
#include "Kara/Events/WindowEvent.hpp"
#include "Kara/Graphics/Command.hpp"
#include "Kara/Layers/Layer.hpp"
#include "Kara/Log/Logger.hpp"
#include "Kara/UI/MainLayer.hpp"
#include "Kara/UI/TestLayer.hpp"

namespace Kara {
Application *Application::smInstance = nullptr;

Application::Application() {
  Log::Logger::Init();

  KARA_CORE_ASSERT(!smInstance, "Application should be a singleton !");
  smInstance = this;

  mWindow.reset(Core::Window::Create());

  mUILayer = new UI::UILayer();
  mLayerStack.PushOverlay(mUILayer);
  mLayerStack.Push(new UI::MainLayer());

  mWindow->SetEventCallback([&](Events::Event &e) { return OnEvent(e); });
}

void Application::Run() {
  while (mRunning) {
    Graphics::Command::Clear({1.0f, 0.0f, 1.0f, 1.0f});

    mLayerStack.map([](Layers::Layer *aLayer) { aLayer->OnUpdate(); });

    mUILayer->Begin();
    mLayerStack.map([](Layers::Layer *aLayer) { aLayer->OnRender(); });
    mUILayer->End();

    mWindow->OnUpdate();
  }
}

void Application::OnEvent(Events::Event &aEvent) {
  Events::Dispatcher dispatcher{aEvent};
  dispatcher.Dispatch<Events::WindowClosedEvent>(
      [&](Events::WindowClosedEvent &e) { return OnClose(e); });

  mLayerStack.mapi([&](Layers::Layer *aLayer) {
    aLayer->OnEvent(aEvent);
    if (aEvent.IsHandled()) {
      return true;
    }
    return false;
  });
}

void Application::Push(Layers::Layer *aLayer) { mLayerStack.Push(aLayer); }

void Application::Pop(Layers::Layer *aLayer) { mLayerStack.Pop(aLayer); }

bool Application::OnClose(Events::WindowClosedEvent &aEvent) {
  mRunning = false;
  return true;
}

} // namespace Kara