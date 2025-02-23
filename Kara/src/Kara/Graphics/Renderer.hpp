#pragma once

#include "Kara/Graphics/IndexBuffer.hpp"
#include "Kara/Graphics/Shader.hpp"
#include "Kara/Graphics/VertexArray.hpp"
#include "Kara/Graphics/VertexBuffer.hpp"

namespace Kara {
namespace Graphics {
enum class RenderApi : uint8_t { None, OpenGl };

class Renderer {
public:
  Renderer(const RenderApi aRenderApi);

  VertexArray *CreateVertexArray();
  IndexBuffer *CreateIndexBuffer(uint32_t *aIndeces, uint32_t aSize);
  VertexBuffer *CreateVertexBuffer(float *aVertices, uint32_t aSize);
  Shader *CreateShader();

private:
  RenderApi mRenderApi;
};
} // namespace Graphics
} // namespace Kara