#include "pch.hpp"

#include "Utils.hpp"

#include "Kara/Application.hpp"

namespace Kara {
namespace UI {
NormalizedRect Rect::Normalize() {
  const auto screenSize = Application::Get()->GetWindow()->GetSize();

  NormalizedRect rect;
  rect.X = static_cast<float>(X) / screenSize.mWidth;
  rect.Y = static_cast<float>(Y) / screenSize.mHeight;
  rect.Width = static_cast<float>(Width) / screenSize.mWidth;
  rect.Height = static_cast<float>(Height) / screenSize.mHeight;

  return rect;
}
} // namespace UI
} // namespace Kara