#pragma once

#include "Kara/Core/Types.hpp"

namespace Kara {
namespace UI {
struct Rect {
  uint32_t X{0}, Y{0}, Width{0}, Height{0};

  Rect(const uint32_t aX, const uint32_t aY, const uint32_t aWidth,
       const uint32_t aHeight)
      : X{aX}, Y{aY}, Width{aWidth}, Height{aHeight} {}
  Rect(const uint32_t aX, const uint32_t aY, const Core::Size &aSize)
      : Rect(aX, aY, aSize.Width, aSize.Height) {}

  Core::Size GetSize() const { return {Width, Height}; }
};

} // namespace UI
} // namespace Kara