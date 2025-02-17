#include "pch.hpp"

#include "ButtonComponent.hpp"

#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace UI {
namespace Internal {
void ButtonComponent::HandleMouseMoved(const Position &aNewPosition) {
  const auto rect = GetRect();
  if (aNewPosition.x >= rect.X && aNewPosition.x <= rect.X + rect.Width ||
      aNewPosition.y >= rect.Y && aNewPosition.y <= rect.Y + rect.Height) {
    mState = State::Hover;
  } else {
    mState = State::Normal;
  }
}

} // namespace Internal
} // namespace UI
} // namespace Kara