#pragma once

#include "Kara/Core/Types.hpp"

namespace Kara {
namespace UI {
//! @brief The 0 window id is reserved for the master window/component
enum class WindowIds {
  MASTER = 0,
};

struct NormalizedRect {
  float X{0}, Y{0}, Width{0}, Height{0};
};

struct Rect {
  uint32_t X{0}, Y{0}, Width{0}, Height{0};

  Rect(const uint32_t aX, const uint32_t aY, const uint32_t aWidth,
       const uint32_t aHeight)
      : X{aX}, Y{aY}, Width{aWidth}, Height{aHeight} {}
  Rect(const uint32_t aX, const uint32_t aY, const Kara::CoreTypes::Size &aSize)
      : Rect(aX, aY, aSize.mWidth, aSize.mHeight) {}

  NormalizedRect Normalize();
};

} // namespace UI
} // namespace Kara