#include "Application.hpp"

#include "Log/Logger.hpp"

namespace Kara {
Application::Application() { Log::Logger::Init(); }

Application::~Application() {}

void Application::Run() {
  while (true)
    ;
}
}  // namespace Kara