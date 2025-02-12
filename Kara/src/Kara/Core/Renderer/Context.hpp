#pragma once

namespace Kara {
namespace Core {
namespace Renderer {
class Context {
public:
  virtual void SwapBuffers() = 0;
  virtual void SwapInterval(const bool aInterval) = 0;
};

} // namespace Renderer
} // namespace Core
} // namespace Kara