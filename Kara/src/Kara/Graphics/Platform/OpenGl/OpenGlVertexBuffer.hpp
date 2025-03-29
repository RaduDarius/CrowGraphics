#pragma once

#include "Kara/Graphics/BufferLayout.hpp"
#include "Kara/Graphics/VertexBuffer.hpp"

namespace Kara {
namespace Graphics {
class OpenGlVertexBuffer : public VertexBuffer {
public:
  OpenGlVertexBuffer(float *aVertices, std::size_t aSize);
  ~OpenGlVertexBuffer() override;

  void Bind() const override;
  void Unbind() const override;

  const BufferLayout &GetLayout() const override { return mLayout; };
  void SetLayout(const BufferLayout &aLayout) override;

private:
  uint32_t mRendererId;

  BufferLayout mLayout{};
};

} // namespace Graphics
} // namespace Kara