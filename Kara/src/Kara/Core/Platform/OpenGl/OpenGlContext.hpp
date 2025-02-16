#pragma once

#include "Kara/Core/Render/Context.hpp"

struct GLFWwindow;

namespace Kara {
namespace Core {
namespace Platform {
class OpenGlContext : public Render::Context {
public:
  OpenGlContext(GLFWwindow *aWindowHandle);

  void SwapBuffers() override;
  void SwapInterval(const bool aInterval) override;

private:
  // DON'T free it, we do not have ownership over it
  GLFWwindow *mWindowHandle;
};
} // namespace Platform
} // namespace Core
} // namespace Kara