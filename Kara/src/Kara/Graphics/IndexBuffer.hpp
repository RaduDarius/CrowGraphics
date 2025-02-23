#pragma once

#include <stdint.h>

namespace Kara {
namespace Graphics {
class IndexBuffer {
public:
  virtual ~IndexBuffer() = default;

  virtual uint32_t Count() const = 0;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

} // namespace Graphics
} // namespace Kara
