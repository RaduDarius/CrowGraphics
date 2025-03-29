#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/ITexture.hpp"

#include <string_view>

namespace Kara {
namespace Graphics {
class Texture : public ITexture {
public:
  Texture(const std::string_view &aPath) {}
  virtual ~Texture() = default;
};

using TextureRef = Core::Ref<Texture>;
} // namespace Graphics
} // namespace Kara