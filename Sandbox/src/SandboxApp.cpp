#include <Kara.hpp>

class Sandbox : public Kara::Application {
 public:
  Sandbox() {
    KARA_CLIENT_INFO("Sandbox app created successfully !");
  }
};

namespace Kara {
Application* CreateApplication() { return new Sandbox(); }
}  // namespace Kara