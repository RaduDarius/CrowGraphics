#pragma once

#include "Kara/Core/Types.hpp"
#include "Kara/Core/Window.hpp"

struct GLFWwindow;

namespace Kara {
namespace Graphics {
class WindowsWindow : public Core::Window {
public:
  WindowsWindow(const Core::WindowProps &aProps);
  ~WindowsWindow() override;

  void OnUpdate() override;

  Core::Size GetSize() const override;
  uint32_t GetWidth() const override;
  uint32_t GetHeight() const override;
  void *GetNativeWindow() const override;

  bool IsVSync() const override;

  void SetEventCallback(const EventCallback &) override;
  void SetVSync(const bool) override;

private:
  void SetupEvents();

  GLFWwindow *mWindow{nullptr};

  // Data
  struct WindowData {
    std::string Title;
    Core::Size Size;
    bool VSync{false};

    EventCallback EventCallback;
  };

  WindowData mData;
};
} // namespace Graphics
} // namespace Kara
