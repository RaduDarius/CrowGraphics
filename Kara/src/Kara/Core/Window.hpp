#pragma once

#include "Kara/Core/Types.hpp"
#include "Kara/Events/Event.hpp"
#include "Kara/Graphics/Context.hpp"

#include <functional>
#include <string>

namespace Kara {
namespace Core {
struct WindowProps {
  WindowProps() = default;
  WindowProps(const std::string aTitle, const CoreTypes::Size aSize)
      : Title{aTitle}, Size{aSize} {}

  std::string Title{"Window app"};
  CoreTypes::Size Size{1280, 720};
};

class Window {
public:
  using EventCallback = std::function<void(Events::Event &)>;

  virtual ~Window();

  virtual void OnUpdate() = 0;

  virtual CoreTypes::Size GetSize() const = 0;
  virtual uint32_t GetWidth() const = 0;
  virtual uint32_t GetHeight() const = 0;
  virtual void *GetNativeWindow() const = 0;

  virtual bool IsVSync() const = 0;

  virtual void SetEventCallback(const EventCallback &) = 0;
  virtual void SetVSync(const bool) = 0;

  static Window *Create(const WindowProps &aProps = WindowProps());

protected:
  //! @brief The caller will lose ownership of [aContext]
  void SetContext(Graphics::Context *aContext);

  //! Context related APIs
  inline void ContextSwapBuffers() { mContext->SwapBuffers(); }
  inline void ContextSwapInterval(const bool aInterval) {
    mContext->SwapInterval(aInterval);
  }

private:
  Graphics::Context *mContext{nullptr};
};

} // namespace Core
} // namespace Kara