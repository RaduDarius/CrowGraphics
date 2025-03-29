#pragma once

namespace Kara {
namespace Graphics {
class ITexture {
public:
  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};
} // namespace Graphics
} // namespace Kara