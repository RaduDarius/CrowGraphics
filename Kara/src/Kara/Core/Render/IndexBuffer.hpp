#pragma once

#include <stdint.h>

namespace Kara {
namespace Core {
namespace Render {
class IndexBuffer {
public:
  virtual ~IndexBuffer() = default;

  virtual uint32_t Count() const = 0;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};

} // namespace Render
} // namespace Core
} // namespace Kara