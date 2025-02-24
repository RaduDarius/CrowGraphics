#pragma once

#include "Kara/Graphics/IndexBuffer.hpp"
#include "Kara/Graphics/Shader.hpp"
#include "Kara/Graphics/Texture.hpp"
#include "Kara/Graphics/VertexArray.hpp"
#include "Kara/Graphics/VertexBuffer.hpp"

#include <string_view>

namespace Kara {
namespace Graphics {
enum class RenderApi : uint8_t { None, OpenGl };

class Renderer {
public:
  Renderer(const RenderApi aRenderApi);

  Core::Ref<VertexArray> CreateVertexArray();
  Core::Ref<IndexBuffer> CreateIndexBuffer(uint32_t *aIndeces, uint32_t aSize);
  Core::Ref<VertexBuffer> CreateVertexBuffer(float *aVertices, uint32_t aSize);
  Core::Ref<Shader> CreateShader(const Shader::Type aShaderType);
  Core::Ref<Texture> CreateTexture(const std::string_view &aPath);

private:
  RenderApi mRenderApi;
};
} // namespace Graphics
} // namespace Kara