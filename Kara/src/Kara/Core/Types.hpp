#pragma once

struct Point {
  float x;
  float y;
};

inline std::ostream& operator<<(std::ostream& os, const Point& point) {
  return os << "(X: " << point.x << " Y: " << point.y << ")";
}
