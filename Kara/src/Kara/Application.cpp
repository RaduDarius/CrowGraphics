#include "pch.hpp"

#include "Application.hpp"

#include "Kara/Core/Render/Command.hpp"
#include "Kara/EventSystem/Dispatcher.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/EventSystem/WindowEvent.hpp"
#include "Kara/LayerSystem/Layer.hpp"
#include "Kara/Log/Logger.hpp"
#include "Kara/UI/MainLayer.hpp"

namespace Kara {
Application *Application::smInstance = nullptr;

Application::Application() {
  Log::Logger::Init();

  smInstance = this;
  KARA_CORE_ASSERT(smInstance, "Application should be a singleton !");

  mWindow.reset(Core::Window::Create());

  mUILayer = new UI::UILayer();
  mLayerStack.PushOverlay(mUILayer);
  mLayerStack.Push(new UI::MainLayer());

  mWindow->SetEventCallback([&](EventSystem::Event &e) { return OnEvent(e); });
}

void Application::Run() {
  while (mRunning) {
    Core::Render::Command::Clear({1.0f, 0.0f, 1.0f, 1.0f});

    mLayerStack.map([](LayerSystem::Layer *aLayer) { aLayer->OnUpdate(); });

    mUILayer->Begin();
    mLayerStack.map([](LayerSystem::Layer *aLayer) { aLayer->OnRender(); });
    mUILayer->End();

    mWindow->OnUpdate();
  }
}

void Application::OnEvent(EventSystem::Event &aEvent) {
  EventSystem::Dispatcher dispatcher{aEvent};
  dispatcher.Dispatch<EventSystem::WindowClosedEvent>(
      [&](Kara::EventSystem::WindowClosedEvent &e) -> bool {
        return OnClose(e);
      });

  mLayerStack.mapi([&](LayerSystem::Layer *aLayer) {
    aLayer->OnEvent(aEvent);
    if (aEvent.IsHandled()) {
      return true;
    }
    return false;
  });
}

void Application::Push(LayerSystem::Layer *aLayer) { mLayerStack.Push(aLayer); }

void Application::Pop(LayerSystem::Layer *aLayer) { mLayerStack.Pop(aLayer); }

bool Application::OnClose(EventSystem::WindowClosedEvent &aEvent) {
  mRunning = false;
  return true;
}

} // namespace Kara