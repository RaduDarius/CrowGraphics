#pragma once

namespace Kara {
namespace Core {
class Context {
public:
  virtual void SwapBuffers() = 0;
  virtual void SwapInterval(const bool aInterval) = 0;
};

} // namespace Core
} // namespace Kara