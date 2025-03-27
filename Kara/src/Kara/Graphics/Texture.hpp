#pragma once

#include "Kara/Core/Core.hpp"

#include <string_view>

namespace Kara {
namespace Graphics {
class Texture {
public:
  Texture(const std::string_view &aPath) {}
  virtual ~Texture() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

using TextureRef = Core::Ref<Texture>;
} // namespace Graphics
} // namespace Kara