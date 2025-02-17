#pragma once

#include "Kara/UI/Core/Component.hpp"

namespace Kara {
namespace UI {
namespace Internal {
class ButtonComponent : public Core::Component {
public:
  ButtonComponent(const Rect &aRect) : Core::Component{aRect} {}

  void HandleMouseMoved(const Position &aNewPosition) override;

private:
  enum class State { Normal, Pressed, Hover };

  State mState{State::Normal};
};

} // namespace Internal
} // namespace UI
} // namespace Kara