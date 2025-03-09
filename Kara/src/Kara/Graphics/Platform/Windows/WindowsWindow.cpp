#include "pch.hpp"

#include "WindowsWindow.hpp"

#include "Kara/Events/Convertors.hpp"
#include "Kara/Events/KeyEvent.hpp"
#include "Kara/Events/MouseEvent.hpp"
#include "Kara/Events/WindowEvent.hpp"
#include "Kara/Graphics/Platform/OpenGl/OpenGlContext.hpp"
#include "Kara/Log/Logger.hpp"

#include <GLFW/glfw3.h>

namespace Kara {
namespace Graphics {
namespace {
auto sGLFWInitialized{false};
}

WindowsWindow::WindowsWindow(const Core::WindowProps &aProps)
    : mData{aProps.Title, aProps.Size} {
  KARA_CORE_INFO("Creating window {0}, {1}", mData.Title,
                 mData.Size.ToString());

  if (!sGLFWInitialized) {
    const auto success = glfwInit();
    KARA_CORE_ASSERT(success, "Can not initialize GLFW !");

    glfwSetErrorCallback([](int aError, const char *aMessage) {
      KARA_CORE_ERROR("GLFW Error: [{0}]: {1}", aError, aMessage);
    });

    sGLFWInitialized = true;
  }

  mWindow = glfwCreateWindow(mData.Size.Width, mData.Size.Height,
                             mData.Title.c_str(), nullptr, nullptr);
  SetContext(new OpenGlContext(mWindow));

  glfwSetWindowUserPointer(mWindow, reinterpret_cast<void *>(&mData));
  SetVSync(true);

  SetupEvents();
}

WindowsWindow::~WindowsWindow() { glfwDestroyWindow(mWindow); }

void WindowsWindow::OnUpdate() {
  glfwPollEvents();
  ContextSwapBuffers();
}

CoreTypes::Size WindowsWindow::GetSize() const { return mData.Size; }

uint32_t WindowsWindow::GetWidth() const { return mData.Size.Width; }

uint32_t WindowsWindow::GetHeight() const { return mData.Size.Height; }

void *WindowsWindow::GetNativeWindow() const {
  return static_cast<void *>(mWindow);
}

bool WindowsWindow::IsVSync() const { return mData.VSync; }

void WindowsWindow::SetEventCallback(const EventCallback &aCallback) {
  mData.EventCallback = aCallback;
}

void WindowsWindow::SetVSync(const bool aEnable) {
  if (aEnable == mData.VSync) {
    return;
  }

  mData.VSync = aEnable;
  ContextSwapInterval(mData.VSync);
}

void WindowsWindow::SetupEvents() {
  glfwSetWindowSizeCallback(
      mWindow, [](GLFWwindow *aWindow, int aWidth, int aHeight) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        Events::WindowResizedEvent event{static_cast<float>(aWidth),
                                         static_cast<float>(aHeight)};
        data.Size.Width = aWidth;
        data.Size.Height = aHeight;
        data.EventCallback(event);
      });

  glfwSetWindowCloseCallback(mWindow, [](GLFWwindow *aWindow) {
    auto data =
        *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

    Events::WindowClosedEvent event;
    data.EventCallback(event);
  });

  glfwSetKeyCallback(mWindow, [](GLFWwindow *aWindow, int aKey, int aScanCode,
                                 int aAction, int aMods) {
    auto data =
        *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

    switch (aAction) {
    case GLFW_PRESS: {
      Events::KeyPressedEvent e{Events::ConvertToKeyCode(aKey), 0};
      data.EventCallback(e);
    } break;

    case GLFW_RELEASE: {
      Events::KeyReleasedEvent e{Events::ConvertToKeyCode(aKey)};
      data.EventCallback(e);
    } break;

    case GLFW_REPEAT: {
      Events::KeyPressedEvent e{Events::ConvertToKeyCode(aKey), 1};
      data.EventCallback(e);
    } break;

    default:
      break;
    }
  });

  glfwSetCharCallback(mWindow, [](GLFWwindow *aWindow, unsigned int aKeyCode) {
    auto data =
        *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

    Events::KeyTypedEvent e{Events::ConvertToKeyCode(aKeyCode)};
    data.EventCallback(e);
  });

  glfwSetMouseButtonCallback(
      mWindow, [](GLFWwindow *aWindow, int aButton, int aAction, int aModes) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        switch (aAction) {
        case GLFW_PRESS: {
          Events::MouseButtonPressedEvent e{
              Events::ConvertToMouseButtonId(aButton)};
          data.EventCallback(e);
        } break;

        case GLFW_RELEASE: {
          Events::MouseButtonReleasedEvent e{
              Events::ConvertToMouseButtonId(aButton)};
          data.EventCallback(e);
        } break;

        default:
          break;
        }
      });

  glfwSetScrollCallback(
      mWindow, [](GLFWwindow *aWindow, double aXOffset, double aYOffset) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        Events::MouseScrolledEvent e{static_cast<float>(aXOffset),
                                     static_cast<float>(aYOffset)};
        data.EventCallback(e);
      });

  glfwSetCursorPosCallback(
      mWindow, [](GLFWwindow *aWindow, double aXPos, double aYPos) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        Events::MouseMovedEvent e{static_cast<float>(aXPos),
                                  static_cast<float>(aYPos)};
        data.EventCallback(e);
      });
}

} // namespace Graphics

namespace Core {
Window *Window::Create(const Core::WindowProps &aProps) {
  return new Graphics::WindowsWindow(aProps);
}
} // namespace Core
} // namespace Kara
