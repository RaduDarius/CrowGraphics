#pragma once

#include "Kara/Core/Types.hpp"
#include "Kara/Core/Window.hpp"

struct GLFWwindow;

namespace Kara {
namespace Core {
namespace Platform {
class KARA_API WindowsWindow : public Window {
 public:
  WindowsWindow(const WindowProps& aProps);
  ~WindowsWindow() override;

  virtual void OnUpdate() override;

  virtual CoreTypes::Size GetSize() const override;
  virtual uint32 GetWidth() const override;
  virtual uint32 GetHeight() const override;
  virtual bool IsVSync() const override;

  virtual void SetEventCallback(const EventCallback&) override;
  virtual void SetVSync(const bool) override;

 private:
  void SetupEvents();

  GLFWwindow* mWindow{nullptr};

  // Data
  struct WindowData {
    std::string mTitle;
    CoreTypes::Size mSize;
    bool mVSync{false};

    EventCallback mEventCallback;
  };

  WindowData mData;
};
}  // namespace Platform
}  // namespace Core
}  // namespace Kara
