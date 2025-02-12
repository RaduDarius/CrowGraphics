#include "pch.hpp"

#include "OpenGlContext.hpp"

#include "Kara/Log/Logger.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Kara {
namespace Core {
namespace Platform {
OpenGlContext::OpenGlContext(GLFWwindow *aWindowHandle)
    : mWindowHandle{aWindowHandle} {
  glfwMakeContextCurrent(mWindowHandle);
  const auto success =
      gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
  KARA_CORE_ASSERT(success, "Can not initialize GLAD !");
}

void OpenGlContext::SwapBuffers() { glfwSwapBuffers(mWindowHandle); }

void OpenGlContext::SwapInterval(const bool aInterval) {
  glfwSwapInterval(static_cast<int>(aInterval));
}
} // namespace Platform
} // namespace Core
} // namespace Kara