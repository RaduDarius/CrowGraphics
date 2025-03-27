#pragma once

#include <string_view>
#include <stdint.h>

namespace Kara {
namespace Image {
enum class Handle : uint32_t {
  None,
  Texture1,

  Count
};

std::string_view GetImagePath(const Handle aHandle);

} // namespace Image
} // namespace Kara