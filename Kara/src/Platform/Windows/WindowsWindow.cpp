#include "pch.hpp"

#include "WindowsWindow.hpp"

#include "Kara/EventSystem/KeyEvent.hpp"
#include "Kara/EventSystem/MouseEvent.hpp"
#include "Kara/EventSystem/WindowEvent.hpp"
#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace Core {
namespace Platform {
namespace {
auto sGLFWInitialized{false};
}

WindowsWindow::WindowsWindow(const WindowProps &aProps)
    : mData{aProps.mTitle, aProps.mSize} {
  KARA_CORE_INFO("Creating window {0}, {1}", mData.mTitle,
                 mData.mSize.ToString());

  if (!sGLFWInitialized) {
    auto success = glfwInit();
    KARA_CORE_ASSERT(success, "Can not initialize GLFW !");

    glfwSetErrorCallback([](int aError, const char *aMessage) {
      KARA_CORE_ERROR("GLFW Error: [{0}]: {1}", aError, aMessage);
    });

    sGLFWInitialized = true;
  }

  mWindow = glfwCreateWindow(mData.mSize.mWidth, mData.mSize.mHeight,
                             mData.mTitle.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(mWindow);
  glfwSetWindowUserPointer(mWindow, reinterpret_cast<void *>(&mData));
  SetVSync(true);

  SetupEvents();
}

WindowsWindow::~WindowsWindow() { glfwDestroyWindow(mWindow); }

void WindowsWindow::OnUpdate() {
  glfwPollEvents();
  glfwSwapBuffers(mWindow);
}

CoreTypes::Size WindowsWindow::GetSize() const { return mData.mSize; }

uint32 WindowsWindow::GetWidth() const { return mData.mSize.mWidth; }

uint32 WindowsWindow::GetHeight() const { return mData.mSize.mHeight; }

bool WindowsWindow::IsVSync() const { return mData.mVSync; }

void WindowsWindow::SetEventCallback(const EventCallback &aCallback) {
  mData.mEventCallback = aCallback;
}

void WindowsWindow::SetVSync(const bool aEnable) {
  if (aEnable == mData.mVSync) {
    return;
  }

  mData.mVSync = aEnable;
  glfwSwapInterval(static_cast<int>(mData.mVSync));
}

void WindowsWindow::SetupEvents() {
  glfwSetWindowSizeCallback(
      mWindow, [](GLFWwindow *aWindow, int aWidth, int aHeight) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        EventSystem::WindowResizedEvent event{static_cast<float>(aWidth),
                                              static_cast<float>(aHeight)};
        data.mEventCallback(event);
        data.mSize.mWidth = aWidth;
        data.mSize.mHeight = aHeight;
      });

  glfwSetWindowCloseCallback(mWindow, [](GLFWwindow *aWindow) {
    auto data =
        *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

    EventSystem::WindowClosedEvent event;
    data.mEventCallback(event);
  });

  glfwSetKeyCallback(mWindow, [](GLFWwindow *aWindow, int aKey, int aScanCode,
                                 int aAction, int aMods) {
    auto data =
        *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

    switch (aAction) {
    case GLFW_PRESS: {
      EventSystem::KeyPressedEvent e{aKey, 0};
      data.mEventCallback(e);
    } break;

    case GLFW_RELEASE: {
      EventSystem::KeyReleasedEvent e{aKey};
      data.mEventCallback(e);
    } break;

    case GLFW_REPEAT: {
      EventSystem::KeyPressedEvent e{aKey, 1};
      data.mEventCallback(e);
    } break;

    default:
      break;
    }
  });

  glfwSetMouseButtonCallback(
      mWindow, [](GLFWwindow *aWindow, int aButton, int aAction, int aModes) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        switch (aAction) {
        case GLFW_PRESS: {
          EventSystem::MouseButtonPressedEvent e{aButton};
          data.mEventCallback(e);
        } break;

        case GLFW_RELEASE: {
          EventSystem::MouseButtonReleasedEvent e{aButton};
          data.mEventCallback(e);
        } break;

        default:
          break;
        }
      });

  glfwSetScrollCallback(
      mWindow, [](GLFWwindow *aWindow, double aXOffset, double aYOffset) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        EventSystem::MouseScrolledEvent e{static_cast<float>(aXOffset),
                                          static_cast<float>(aYOffset)};
        data.mEventCallback(e);
      });

  glfwSetCursorPosCallback(
      mWindow, [](GLFWwindow *aWindow, double aXPos, double aYPos) {
        auto data =
            *reinterpret_cast<WindowData *>(glfwGetWindowUserPointer(aWindow));

        EventSystem::MouseMovedEvent e{static_cast<float>(aXPos),
                                       static_cast<float>(aYPos)};
        data.mEventCallback(e);
      });
}

} // namespace Platform

Window *Window::Create(const WindowProps &aProps) {
  return new Platform::WindowsWindow(aProps);
}
} // namespace Core
} // namespace Kara
