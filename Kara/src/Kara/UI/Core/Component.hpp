#pragma once

#include "Kara/Core/Render/Renderer.hpp"
#include "Kara/Core/Render/Shader.hpp"
#include "Kara/Core/Render/VertexArray.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/UI/Core/EventHandler.hpp"
#include "Kara/UI/Core/IRenderable.hpp"
#include "Kara/UI/Utils.hpp"

#include <memory>

namespace Kara {
namespace UI {
namespace Core {
class Component : public IRenderable, public EventHandler {
public:
  Component(const Rect &aRect);

  inline Rect GetRect() const { return mRect; }

  void Render() override;

private:
  std::unique_ptr<Kara::Core::Render::Renderer> mRenderer;

  std::shared_ptr<Kara::Core::Render::Shader> mShader;
  std::shared_ptr<Kara::Core::Render::VertexArray> mVertexArray;

  Rect mRect;
};
} // namespace Core
} // namespace UI
} // namespace Kara