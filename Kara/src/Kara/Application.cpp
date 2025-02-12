#include "pch.hpp"

#include "Application.hpp"

#include "Kara/EventSystem/Dispatcher.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/EventSystem/WindowEvent.hpp"
#include "Kara/LayerSystem/Layer.hpp"
#include "Kara/Log/Logger.hpp"

#include <glad/glad.h>

namespace Kara {
Application *Application::smInstance = nullptr;

Application::Application() {
  Log::Logger::Init();

  smInstance = this;
  KARA_CORE_ASSERT(smInstance, "Application should be a singleton !");

  mWindow = std::unique_ptr<Core::Window>(Core::Window::Create());

  mUILayer = new UI::UILayer();
  mLayerStack.PushOverlay(mUILayer);

  mWindow->SetEventCallback([&](EventSystem::Event &e) { return OnEvent(e); });
}

void Application::Run() {
  while (mRunning) {
    glClearColor(1, 0, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    mLayerStack.map([](LayerSystem::Layer *aLayer) { aLayer->OnUpdate(); });

    mUILayer->Begin();
    mLayerStack.map([](LayerSystem::Layer *aLayer) { aLayer->OnRender(); });
    mUILayer->End();

    mWindow->OnUpdate();
  }
}

void Application::OnEvent(EventSystem::Event &aEvent) {
  // KARA_CORE_TRACE("{0}", aEvent.ToString());

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