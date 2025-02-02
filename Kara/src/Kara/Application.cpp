#include "pch.hpp"

#include "Application.hpp"

#include "Kara/EventSystem/Dispatcher.hpp"
#include "Kara/Log/Logger.hpp"

namespace Kara {
Application::Application() {
  Log::Logger::Init();
  mWindow = std::unique_ptr<Core::Window>(Core::Window::Create());
  mWindow->SetEventCallback(
      [&](EventSystem::Event& e) { return OnEvent(e); });
}

void Application::Run() {
  while (mRunning) {
    mWindow->OnUpdate();
  }
}

void Application::OnEvent(EventSystem::Event& aEvent) {
  KARA_CORE_TRACE("{0}", aEvent.ToString());

  EventSystem::Dispatcher dispatcher{aEvent};

  dispatcher.Dispatch<EventSystem::WindowClosedEvent>(
      [&](Kara::EventSystem::WindowClosedEvent& e) -> bool {
        return OnClose(e);
      });
}

bool Application::OnClose(EventSystem::WindowClosedEvent& aEvent) {
  mRunning = false;
  return true;
}

}  // namespace Kara