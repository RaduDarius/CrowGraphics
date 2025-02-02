#pragma once

#include "Core/Core.hpp"

namespace Kara {
class KARA_API Application {
 public:
  Application();
  virtual ~Application();

  void Run();
};

Application* CreateApplication();
}  // namespace Kara
