#pragma once

namespace Kara {
namespace Core {
namespace Render {
class Context {
public:
  virtual void SwapBuffers() = 0;
  virtual void SwapInterval(const bool aInterval) = 0;
};

} // namespace Render
} // namespace Core
} // namespace Kara