#pragma once

namespace Kara {
namespace EventSystem {
enum class MouseButtonId {
  Button1 = 0,
  Button2,
  Button3,
  Button4,
  Button5,
  Button6,
  Button7,
  Button8,

  // Shortcats
  ButtonLast = Button8,
  ButtonLeft = Button1,
  ButtonRight = Button2,
  ButtonMiddle = Button3,
};

inline std::ostream &operator<<(std::ostream &os, MouseButtonId aButton) {
  switch (aButton) {
  case MouseButtonId::Button1:
    os << "Mouse Button 1";
    break;
  case MouseButtonId::Button2:
    os << "Mouse Button 2";
    break;
  case MouseButtonId::Button3:
    os << "Mouse Button 3";
    break;
  case MouseButtonId::Button4:
    os << "Mouse Button 4";
    break;
  case MouseButtonId::Button5:
    os << "Mouse Button 5";
    break;
  case MouseButtonId::Button6:
    os << "Mouse Button 6";
    break;
  case MouseButtonId::Button7:
    os << "Mouse Button 7";
    break;
  case MouseButtonId::Button8:
    os << "Mouse Button 8";
    break;
  default:
    os << "Unknown Mouse Button";
    break;
  }
  return os;
}
} // namespace EventSystem
} // namespace Kara