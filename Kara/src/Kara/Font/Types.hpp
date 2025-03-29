#pragma once

#include <glm/glm.hpp>

namespace Kara {
namespace Font {
enum class Handle {
  Arial,

  Count
};

struct Glyph {
  glm::ivec2 Size;    // width/height of the glyph bitmap
  glm::ivec2 Bearing; // offset from baseline (bitmap_left, bitmap_top)
  int Advance;        // cursor advance (in pixels)
  glm::vec2 UvOffset; // UV top-left in the atlas
  glm::vec2 UvSize;   // width/height in UV space
};
}
} // namespace Kara