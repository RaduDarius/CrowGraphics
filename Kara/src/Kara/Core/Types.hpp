#pragma once

#include <sstream>
#include <string>

namespace Kara {
namespace CoreTypes {
struct PixelPoint {
  uint32_t mX;
  uint32_t mY;

  std::string ToString() {
    std::stringstream ss;
    ss << "(X: " << mX << " Y: " << mY << ")";
    return ss.str();
  }
};

struct Size {
  uint32_t mWidth;
  uint32_t mHeight;

  std::string ToString() {
    std::stringstream ss;
    ss << "(width: " << mWidth << " height: " << mHeight << ")";
    return ss.str();
  }

  Size operator/(const int aScalar) const {
    return {mWidth / aScalar, mHeight / aScalar};
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