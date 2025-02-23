#pragma once

namespace Kara {
namespace Graphics {
class Context {
public:
  virtual void SwapBuffers() = 0;
  virtual void SwapInterval(const bool aInterval) = 0;
};

} // namespace Graphics
} // namespace Kara