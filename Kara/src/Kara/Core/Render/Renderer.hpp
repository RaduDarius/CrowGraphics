#pragma once

#include "Kara/Core/Render/IndexBuffer.hpp"
#include "Kara/Core/Render/Shader.hpp"
#include "Kara/Core/Render/VertexArray.hpp"
#include "Kara/Core/Render/VertexBuffer.hpp"

#include <memory>

namespace Kara {
namespace Core {
namespace Render {
enum class RenderApi : uint8_t { None, OpenGl };

class Renderer {
public:
  Renderer(const RenderApi aRenderApi);

  void RenderTriangle();

private:
  void CreateVertexArray();
  void CreateIndexBuffer(uint32_t *aIndeces, uint32_t aSize);
  void CreateVertexBuffer(float *aVertices, uint32_t aSize);

  RenderApi mRenderApi;

  std::unique_ptr<Shader> mShader;
  std::unique_ptr<VertexArray> mVertexArray;
  std::shared_ptr<IndexBuffer> mIndexBuffer;
  std::shared_ptr<VertexBuffer> mVertexBuffer;
};
} // namespace Render
} // namespace Core
} // namespace Kara