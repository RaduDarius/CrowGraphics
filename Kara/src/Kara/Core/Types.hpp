#pragma once

#include <sstream>
#include <string>

namespace Kara {
namespace CoreTypes {
struct PixelPoint {
  uint32_t X;
  uint32_t Y;

  std::string ToString() {
    std::stringstream ss;
    ss << "(X: " << X << " Y: " << Y << ")";
    return ss.str();
  }
};

struct Size {
  uint32_t Width;
  uint32_t Height;

  std::string ToString() {
    std::stringstream ss;
    ss << "(width: " << Width << " height: " << Height << ")";
    return ss.str();
  }

  Size operator/(const int aScalar) const {
    return {Width / aScalar, Height / aScalar};
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