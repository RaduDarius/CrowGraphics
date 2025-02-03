#include "pch.hpp"

#include "Application.hpp"

#include "Kara/EventSystem/Dispatcher.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/EventSystem/WindowEvent.hpp"
#include "Kara/LayerSystem/Layer.hpp"
#include "Kara/Log/Logger.hpp"

namespace Kara {
Application::Application() {
  Log::Logger::Init();

  mWindow = std::unique_ptr<Core::Window>(Core::Window::Create());
  mLayerStack = std::make_unique<LayerSystem::LayerStack>();

  mWindow->SetEventCallback([&](EventSystem::Event &e) { return OnEvent(e); });
}

void Application::Run() {
  while (mRunning) {
    for (auto layer : *mLayerStack) {
      layer->OnUpdate();
    }

    mWindow->OnUpdate();
  }
}

void Application::OnEvent(EventSystem::Event &aEvent) {
  KARA_CORE_TRACE("{0}", aEvent.ToString());

  EventSystem::Dispatcher dispatcher{aEvent};
  dispatcher.Dispatch<EventSystem::WindowClosedEvent>(
      [&](Kara::EventSystem::WindowClosedEvent &e) -> bool {
        return OnClose(e);
      });

  for (auto it = mLayerStack->end(); it != mLayerStack->begin();) {
    (*--it)->OnEvent(aEvent);
    if (aEvent.IsHandled()) {
      break;
    }
  }
}

void Application::Push(LayerSystem::Layer *aLayer) {
  mLayerStack->Push(aLayer);
}

void Application::Pop(LayerSystem::Layer *aLayer) { mLayerStack->Pop(aLayer); }

bool Application::OnClose(EventSystem::WindowClosedEvent &aEvent) {
  mRunning = false;
  return true;
}

} // namespace Kara