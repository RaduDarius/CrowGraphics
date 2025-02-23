#pragma once

#include "Kara/Graphics/IndexBuffer.hpp"

namespace Kara {
namespace Graphics {
class OpenGlIndexBuffer : public IndexBuffer {
public:
  OpenGlIndexBuffer(uint32_t *aIndeces, uint32_t aSize);
  ~OpenGlIndexBuffer() override;

  uint32_t Count() const override;

  void Bind() const override;
  void Unbind() const override;

private:
  uint32_t mRendererId;
  uint32_t mCount;
};

} // namespace Graphics
} // namespace Kara