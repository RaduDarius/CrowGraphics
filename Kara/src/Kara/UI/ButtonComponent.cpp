#include "pch.hpp"

#include "ButtonComponent.hpp"

#include "Kara/Core/InputManager.hpp"
#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace UI {
namespace {
constexpr Component::Color NormalColor{0.0f, 0.0f, 1.0f, 1.0f};
constexpr Component::Color HoverColor{0.0f, 1.0f, 1.0f, 0.8f};
constexpr Component::Color PressedColor{0.0f, 0.0f, 1.0f, 0.5f};
} // namespace

ButtonComponent::ButtonComponent(const Rect &aRect) : Component{aRect} {
  SetColor(NormalColor);
}

void ButtonComponent::OnUpdate() {
  auto [newX, newY] = Core::InputManager::GetMousePos();

  const auto rect = GetRect();
  if (newX >= rect.X && newX <= rect.X + rect.Width && newY >= rect.Y &&
      newY <= rect.Y + rect.Height) {
    mState = State::Hover;
    SetColor(HoverColor);
  } else {
    mState = State::Normal;
    SetColor(NormalColor);
  }
}

} // namespace UI
} // namespace Kara