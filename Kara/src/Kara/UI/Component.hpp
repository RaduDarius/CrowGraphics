#pragma once

#include "Kara/UI/Utils.hpp"

#include <glm/glm.hpp>

namespace Kara {
namespace UI {
class Component {
public:
  using Color = glm::vec4;

  Component(const Rect &aRect);

private:
  Rect mRect;
};
} // namespace UI
} // namespace Kara