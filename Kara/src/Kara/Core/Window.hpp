#pragma once

#include "Kara/Core/Types.hpp"
#include "Kara/EventSystem/Event.hpp"

namespace Kara {
namespace Core {
struct KARA_API WindowProps {
  WindowProps() = default;
  WindowProps(const std::string aTitle, const CoreTypes::Size aSize)
      : mTitle{aTitle}, mSize{aSize} {}

  std::string mTitle{"Window app"};
  CoreTypes::Size mSize{1280, 720};
};

class KARA_API Window {
 public:
  using EventCallback = std::function<void(EventSystem::Event&)>;

  virtual ~Window() = default;

  virtual void OnUpdate() = 0;

  virtual CoreTypes::Size GetSize() const = 0;
  virtual uint32 GetWidth() const = 0;
  virtual uint32 GetHeight() const = 0;
  virtual bool IsVSync() const = 0;

  virtual void SetEventCallback(const EventCallback&) = 0;
  virtual void SetVSync(const bool) = 0;

  static Window* Create(const WindowProps& aProps = WindowProps());
};

}  // namespace Core
}  // namespace Kara