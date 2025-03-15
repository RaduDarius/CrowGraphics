#pragma once

#include "Kara/UI/Component.hpp"
#include "Kara/UI/Utils.hpp"

namespace Kara {
namespace UI {
class Desktop : public Component {
public:
  using Component::Params;

  Desktop(const ComponentRef aParent, const Rect &aRect, const Params &aParams);
};
} // namespace UI
} // namespace Kara