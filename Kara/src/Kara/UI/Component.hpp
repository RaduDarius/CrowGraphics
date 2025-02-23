#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Events/Event.hpp"
#include "Kara/Graphics/Renderer.hpp"
#include "Kara/Graphics/Shader.hpp"
#include "Kara/Graphics/VertexArray.hpp"
#include "Kara/UI/IRenderable.hpp"
#include "Kara/UI/IUpdatable.hpp"
#include "Kara/UI/Utils.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Kara {
namespace UI {
class Component : public IRenderable, public IUpdatable {
public:
  using Color = glm::vec4;

  Component(const Rect &aRect);

  inline Rect GetRect() const { return mRect; }

  inline void SetColor(const Color &aColor) { mColor = aColor; }

  void Render() override;
  void OnUpdate() override {}

private:
  Core::Scope<Graphics::Renderer> mRenderer;

  Core::Ref<Graphics::Shader> mShader;
  Core::Ref<Graphics::VertexArray> mVertexArray;

  Color mColor;
  Rect mRect;
};
} // namespace UI
} // namespace Kara