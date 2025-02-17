#pragma once

#include "Kara/Core/Render/IndexBuffer.hpp"
#include "Kara/Core/Render/VertexArray.hpp"
#include "Kara/Core/Render/VertexBuffer.hpp"

namespace Kara {
namespace Core {
namespace Render {
enum class RenderApi : uint8_t { None, OpenGl };

class Renderer {
public:
  Renderer(const RenderApi aRenderApi);

  VertexArray *CreateVertexArray();
  IndexBuffer *CreateIndexBuffer(uint32_t *aIndeces, uint32_t aSize);
  VertexBuffer *CreateVertexBuffer(float *aVertices, uint32_t aSize);

private:
  RenderApi mRenderApi;
};
} // namespace Render
} // namespace Core
} // namespace Kara