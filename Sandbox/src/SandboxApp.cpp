#include <Kara.hpp>

class Sandbox : public Kara::Application {
 public:
  Sandbox() {
    KARA_CLIENT_INFO("Sandbox app created successfully !");
    Push(new Kara::UI::UILayer());
  }
};

namespace Kara {
Application* CreateApplication() { return new Sandbox(); }
}  // namespace Kara