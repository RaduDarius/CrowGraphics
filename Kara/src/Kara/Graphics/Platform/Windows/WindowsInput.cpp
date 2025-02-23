#include "pch.hpp"

#include "Kara/Application.hpp"
#include "Kara/Core/InputManager.hpp"
#include "Kara/Events/Convertors.hpp"

#include <GLFW/glfw3.h>

namespace Kara {
namespace Core {
namespace InputManager {
std::pair<float, float> GetMousePos() {
  auto window = static_cast<GLFWwindow *>(
      Application::Get()->GetWindow()->GetNativeWindow());

  double x, y;
  glfwGetCursorPos(window, &x, &y);
  return {static_cast<float>(x), static_cast<float>(y)};
}

bool IsKeyPressed(const Events::KeyCode aKeyCode) {
  auto window = static_cast<GLFWwindow *>(
      Application::Get()->GetWindow()->GetNativeWindow());

  const auto status = glfwGetKey(window, Events::ConvertToGlfwCode(aKeyCode));

  return status == GLFW_PRESS || status == GLFW_REPEAT;
}

bool IsMouseButtonPressed(const Events::MouseButtonId aButtonId) {
  auto window = static_cast<GLFWwindow *>(
      Application::Get()->GetWindow()->GetNativeWindow());

  const auto status =
      glfwGetMouseButton(window, Events::ConvertToGlfwButton(aButtonId));

  return status == GLFW_PRESS;
}

} // namespace InputManager
} // namespace Core
} // namespace Kara