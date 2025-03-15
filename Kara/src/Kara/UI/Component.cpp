#include "pch.hpp"

#include "Component.hpp"

namespace Kara {
namespace UI {
Component::Component(const ComponentRef aParent, const Rect &aRect,
                     const Params &aParams)
    : mParent{aParent}, mRect{aRect} {
  SetupRenderPrimitives();
}

void Component::AddChild(const ComponentRef aChild) {
  mChildren.emplace_back(aChild);
}

void Component::RemoveChild(const ComponentRef aChild) {
  mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), aChild),
                  mChildren.end());
  aChild->SetParent(nullptr);
  // TODO: Send a notification to ComponentMananger to delete this child,
  // because only desktop should be a root.
}

void Component::SetupRenderPrimitives() {
  mRenderProp = std::make_shared<RenderObject>();

  const float x = static_cast<float>(mRect.X);
  const float y = static_cast<float>(mRect.Y);
  const float width = static_cast<float>(mRect.Width);
  const float height = static_cast<float>(mRect.Height);

  mRenderProp->Vertices = {
      x,         y,          0.0f, x + width, y,          0.0f,
      x + width, y + height, 0.0f, x,         y + height, 0.0f,
  };

  mRenderProp->Indeces = {0, 1, 2, 2, 3, 0};

  mRenderProp->Layout = {
      {Graphics::BufferElementType::Float3, "inPosition"},
  };
}

} // namespace UI
} // namespace Kara