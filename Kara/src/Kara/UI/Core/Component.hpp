#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Render/Renderer.hpp"
#include "Kara/Core/Render/Shader.hpp"
#include "Kara/Core/Render/VertexArray.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/UI/Core/IRenderable.hpp"
#include "Kara/UI/Core/IUpdatable.hpp"
#include "Kara/UI/Utils.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace Kara {
namespace UI {
namespace Core {
class Component : public IRenderable, public IUpdatable {
public:
  using Color = glm::vec4;

  Component(const Rect &aRect);

  inline Rect GetRect() const { return mRect; }

  inline void SetColor(const Color &aColor) { mColor = aColor; }

  void Render() override;
  void OnUpdate() override {}

private:
  Kara::Core::Scope<Kara::Core::Render::Renderer> mRenderer;

  Kara::Core::Ref<Kara::Core::Render::Shader> mShader;
  Kara::Core::Ref<Kara::Core::Render::VertexArray> mVertexArray;

  Color mColor;
  Rect mRect;
};
} // namespace Core
} // namespace UI
} // namespace Kara