#pragma once

#include "Kara/UI/Component.hpp"

namespace Kara {
namespace UI {
class ButtonComponent : public Component {
public:
  ButtonComponent(const Rect &aRect);

  void OnUpdate() override;

private:
  enum class State { Normal, Pressed, Hover };

  State mState{State::Normal};
};

} // namespace UI
} // namespace Kara