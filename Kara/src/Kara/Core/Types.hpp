#pragma once

#include <sstream>
#include <string>

using uint32 = uint32_t;

namespace Kara {
namespace CoreTypes {
struct PixelPoint {
  uint32 mX;
  uint32 mY;

  std::string ToString() {
    std::stringstream ss;
    ss << "(X: " << mX << " Y: " << mY << ")";
    return ss.str();
  }
};

struct Size {
  uint32 mWidth;
  uint32 mHeight;

  std::string ToString() {
    std::stringstream ss;
    ss << "(width: " << mWidth << " height: " << mHeight << ")";
    return ss.str();
  }
};

} // namespace CoreTypes

struct Point {
  float x;
  float y;
};

inline std::ostream &operator<<(std::ostream &os, const Point &point) {
  return os << "(X: " << point.x << " Y: " << point.y << ")";
}
} // namespace Kara