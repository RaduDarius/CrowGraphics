#include "pch.hpp"

#include "Types.hpp"

namespace Kara {
namespace Image {
// TODO: Add error handling
std::string_view GetImagePath(const Handle aHandle) {
  static const auto ImageTable = std::unordered_map<Handle, std::string_view>({
      {Handle::None, ""},
      {Handle::Texture1, "../Kara/assets/textures/texture_test_2.jpg"},
  });

  return ImageTable.find(aHandle)->second;
}

} // namespace Image
} // namespace Kara