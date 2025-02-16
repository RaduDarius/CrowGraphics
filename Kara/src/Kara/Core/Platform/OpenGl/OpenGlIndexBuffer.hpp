#pragma once

#include "Kara/Core/Render/IndexBuffer.hpp"

namespace Kara {
namespace Core {
namespace Platform {
class OpenGlIndexBuffer : public Render::IndexBuffer {
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

} // namespace Platform
} // namespace Core
} // namespace Kara