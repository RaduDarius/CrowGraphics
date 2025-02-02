#include "pch.hpp"

#include "Application.hpp"

#include "Kara/EventSystem/WindowEvent.hpp"
#include "Kara/Log/Logger.hpp"

namespace Kara {
Application::Application() { Log::Logger::Init(); }

Application::~Application() {}

void Application::Run() {
  EventSystem::WindowResizedEvent e{1280, 720};
  KARA_CORE_TRACE(e.ToString());

  while (true)
    ;
}
}  // namespace Kara