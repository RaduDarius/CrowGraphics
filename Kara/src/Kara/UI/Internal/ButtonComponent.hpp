#pragma once

#include "Kara/UI/Core/Component.hpp"

namespace Kara {
namespace UI {
namespace Internal {
class ButtonComponent : public Core::Component {
public:
  ButtonComponent(const Rect &aRect);

  void OnUpdate() override;

private:
  enum class State { Normal, Pressed, Hover };

  State mState{State::Normal};
};

} // namespace Internal
} // namespace UI
} // namespace Kara