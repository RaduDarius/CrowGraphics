#include "pch.hpp"

#include "Utils.hpp"

namespace Kara {
namespace Font {
std::string_view GetFaceTypePath(const Handle aFaceType) {
  static const auto FontFaceTable =
      std::unordered_map<Handle, std::string_view>({
          {Handle::Arial, "C:\\Windows\\Fonts\\Arial.ttf"},
      });

  return FontFaceTable.find(aFaceType)->second;
}
} // namespace Font
} // namespace Kara