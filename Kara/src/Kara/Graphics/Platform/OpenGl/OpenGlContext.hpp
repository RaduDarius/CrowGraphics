#pragma once

#include "Kara/Graphics/Context.hpp"

struct GLFWwindow;

namespace Kara {
namespace Graphics {
class OpenGlContext : public Context {
public:
  OpenGlContext(GLFWwindow *aWindowHandle);

  void SwapBuffers() override;
  void SwapInterval(const bool aInterval) override;

private:
  // DON'T free it, we do not have ownership over it
  GLFWwindow *mWindowHandle;
};
} // namespace Graphics
} // namespace Kara
