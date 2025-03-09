#pragma once

#include "Kara/UI/Utils.hpp"

#include <glm/glm.hpp>

namespace Kara {
namespace UI {
struct RenderObj {};

class Component {
public:
  using Color = glm::vec4;
  struct Params {};

  Component(const Rect &aRect, const Params& aParams);

  inline const RenderObj &GetRenderObj() const { return mRenderObj; };

private:
  // Data Properties
  Rect mRect;

  // Render Properties
  RenderObj mRenderObj;
};
} // namespace UI
} // namespace Kara