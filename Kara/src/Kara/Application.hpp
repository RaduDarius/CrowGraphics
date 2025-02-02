#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Window.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/EventSystem/WindowEvent.hpp"

namespace Kara {
class KARA_API Application {
 public:
  Application();

  void Run();

  void OnEvent(EventSystem::Event& aEvent);

 private:
  bool OnClose(EventSystem::WindowClosedEvent& aEvent);

  std::unique_ptr<Core::Window> mWindow;
  bool mRunning{true};
};

Application* CreateApplication();
}  // namespace Kara
