#pragma once

#include "Kara/Core/Render/BufferLayout.hpp"
#include "Kara/Core/Render/VertexBuffer.hpp"

namespace Kara {
namespace Core {
namespace Platform {
class OpenGlVertexBuffer : public Render::VertexBuffer {
public:
  OpenGlVertexBuffer(float *aVertices, uint32_t aSize);
  ~OpenGlVertexBuffer() override;

  void Bind() const override;
  void Unbind() const override;

  const Render::BufferLayout &GetLayout() const override { return mLayout; };
  void SetLayout(const Render::BufferLayout &aLayout) override;

private:
  uint32_t mRendererId;

  Render::BufferLayout mLayout{};
};

} // namespace Platform
} // namespace Core
} // namespace Kara