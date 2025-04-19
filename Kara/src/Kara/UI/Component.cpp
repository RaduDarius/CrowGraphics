#include "pch.hpp"

#include "Component.hpp"

#include "Kara/Graphics/Render2D.hpp"
#include "Kara/Graphics/Types.hpp"

namespace Kara {
namespace UI {
Component::Component(const ComponentRef aParent, const Rect &aRect,
                     const Params &aParams)
    : mParent{aParent}, mRect{aRect}, mMaterial{
                                          std::make_shared<Graphics::Material>(
                                              Graphics::Color{1.0f, 1.0f, 1.0f,
                                                              1.0f})} {}

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

void Component::OnRender() {
  Graphics::Render2D::SubmitQuad(
      {{mRect.X, mRect.Y}, {mRect.Width, mRect.Height}}, mMaterial);
}

} // namespace UI
} // namespace Kara