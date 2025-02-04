#pragma once

namespace Kara {
namespace EventSystem {
enum class KeyCode {
  None,

  Space,
  Apostrophe,  // '
  Comma,       // ,
  Minus,       // -
  Period,      // .
  Slash,       // /
  Semicolon,   // ;
  Equal,       // =
  LeftBracket, // [
  Backslash,   // \ 
  RightBracket, // ]
  GraveAccent, // `

  //! Number keys
  Key0,
  Key1,
  Key2,
  Key3,
  Key4,
  Key5,
  Key6,
  Key7,
  Key8,
  Key9,

  //! Letter keys
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  U,
  V,
  W,
  X,
  Y,
  Z,

  //! Function keys
  Escape,
  Enter,
  Tab,
  Backspace,
  Insert,
  Delete,

  RightArrow,
  LeftArrow,
  DownArrow,
  UpArrow,

  PageUp,
  PageDown,

  Home,
  End,
  CapsLock,
  ScrollLock,
  NumLock,
  PrintScreen,
  Pause,

  F1,
  F2,
  F3,
  F4,
  F5,
  F6,
  F7,
  F8,
  F9,
  F10,
  F11,
  F12,
  F13,
  F14,
  F15,
  F16,
  F17,
  F18,
  F19,
  F20,
  F21,
  F22,
  F23,
  F24,
  F25,

  //! Numpad keys
  KP0,
  KP1,
  KP2,
  KP3,
  KP4,
  KP5,
  KP6,
  KP7,
  KP8,
  KP9,

  KPDecimal,
  KPDivide,
  KPMultiply,
  KPSubtract,
  KPAdd,
  KPEnter,
  KPEqual,

  // ! Special keys
  LeftShift,
  LeftControl,
  LeftAlt,
  LeftSuper, // Windows / Control key
  RightShift,
  RightControl,
  RightAlt,
  RightSuper,
  Menu

};

inline std::ostream &operator<<(std::ostream &os, KeyCode aKeyCode) {
  switch (aKeyCode) {
  case KeyCode::Space:
    os << " ";
    break;
  case KeyCode::Apostrophe:
    os << "'";
    break;
  case KeyCode::Comma:
    os << ",";
    break;
  case KeyCode::Minus:
    os << "-";
    break;
  case KeyCode::Period:
    os << ".";
    break;
  case KeyCode::Slash:
    os << "/";
    break;
  case KeyCode::Semicolon:
    os << ";";
    break;
  case KeyCode::Equal:
    os << "=";
    break;
  case KeyCode::LeftBracket:
    os << "[";
    break;
  case KeyCode::Backslash:
    os << "\\";
    break;
  case KeyCode::RightBracket:
    os << "]";
    break;
  case KeyCode::GraveAccent:
    os << "`";
    break;
  case KeyCode::Key0:
    os << "0";
    break;
  case KeyCode::Key1:
    os << "1";
    break;
  case KeyCode::Key2:
    os << "2";
    break;
  case KeyCode::Key3:
    os << "3";
    break;
  case KeyCode::Key4:
    os << "4";
    break;
  case KeyCode::Key5:
    os << "5";
    break;
  case KeyCode::Key6:
    os << "6";
    break;
  case KeyCode::Key7:
    os << "7";
    break;
  case KeyCode::Key8:
    os << "8";
    break;
  case KeyCode::Key9:
    os << "9";
    break;
  case KeyCode::A:
    os << "A";
    break;
  case KeyCode::B:
    os << "B";
    break;
  case KeyCode::C:
    os << "C";
    break;
  case KeyCode::D:
    os << "D";
    break;
  case KeyCode::E:
    os << "E";
    break;
  case KeyCode::F:
    os << "F";
    break;
  case KeyCode::G:
    os << "G";
    break;
  case KeyCode::H:
    os << "H";
    break;
  case KeyCode::I:
    os << "I";
    break;
  case KeyCode::J:
    os << "J";
    break;
  case KeyCode::K:
    os << "K";
    break;
  case KeyCode::L:
    os << "L";
    break;
  case KeyCode::M:
    os << "M";
    break;
  case KeyCode::N:
    os << "N";
    break;
  case KeyCode::O:
    os << "O";
    break;
  case KeyCode::P:
    os << "P";
    break;
  case KeyCode::Q:
    os << "Q";
    break;
  case KeyCode::R:
    os << "R";
    break;
  case KeyCode::S:
    os << "S";
    break;
  case KeyCode::T:
    os << "T";
    break;
  case KeyCode::U:
    os << "U";
    break;
  case KeyCode::V:
    os << "V";
    break;
  case KeyCode::W:
    os << "W";
    break;
  case KeyCode::X:
    os << "X";
    break;
  case KeyCode::Y:
    os << "Y";
    break;
  case KeyCode::Z:
    os << "Z";
    break;
  case KeyCode::Escape:
    os << "Escape";
    break;
  case KeyCode::Enter:
    os << "Enter";
    break;
  case KeyCode::Tab:
    os << "Tab";
    break;
  case KeyCode::Backspace:
    os << "Backspace";
    break;
  case KeyCode::Insert:
    os << "Insert";
    break;
  case KeyCode::Delete:
    os << "Delete";
    break;
  case KeyCode::RightArrow:
    os << "Right Arrow";
    break;
  case KeyCode::LeftArrow:
    os << "Left Arrow";
    break;
  case KeyCode::DownArrow:
    os << "Down Arrow";
    break;
  case KeyCode::UpArrow:
    os << "Up Arrow";
    break;
  case KeyCode::PageUp:
    os << "Page Up";
    break;
  case KeyCode::PageDown:
    os << "Page Down";
    break;
  case KeyCode::Home:
    os << "Home";
    break;
  case KeyCode::End:
    os << "End";
    break;
  case KeyCode::CapsLock:
    os << "CapsLock";
    break;
  case KeyCode::ScrollLock:
    os << "ScrollLock";
    break;
  case KeyCode::NumLock:
    os << "NumLock";
    break;
  case KeyCode::PrintScreen:
    os << "PrintScreen";
    break;
  case KeyCode::Pause:
    os << "Pause";
    break;
  case KeyCode::F1:
    os << "F1";
    break;
  case KeyCode::F2:
    os << "F2";
    break;
  case KeyCode::F3:
    os << "F3";
    break;
  case KeyCode::F4:
    os << "F4";
    break;
  case KeyCode::F5:
    os << "F5";
    break;
  case KeyCode::F6:
    os << "F6";
    break;
  case KeyCode::F7:
    os << "F7";
    break;
  case KeyCode::F8:
    os << "F8";
    break;
  case KeyCode::F9:
    os << "F9";
    break;
  case KeyCode::F10:
    os << "F10";
    break;
  case KeyCode::F11:
    os << "F11";
    break;
  case KeyCode::F12:
    os << "F12";
    break;
  case KeyCode::F13:
    os << "F13";
    break;
  case KeyCode::F14:
    os << "F14";
    break;
  case KeyCode::F15:
    os << "F15";
    break;
  case KeyCode::F16:
    os << "F16";
    break;
  case KeyCode::F17:
    os << "F17";
    break;
  case KeyCode::F18:
    os << "F18";
    break;
  case KeyCode::F19:
    os << "F19";
    break;
  case KeyCode::F20:
    os << "F20";
    break;
  case KeyCode::F21:
    os << "F21";
    break;
  case KeyCode::F22:
    os << "F22";
    break;
  case KeyCode::F23:
    os << "F23";
    break;
  case KeyCode::F24:
    os << "F24";
    break;
  case KeyCode::F25:
    os << "F25";
    break;
  case KeyCode::KP0:
    os << "KeyPad 0";
    break;
  case KeyCode::KP1:
    os << "KeyPad 1";
    break;
  case KeyCode::KP2:
    os << "KeyPad 2";
    break;
  case KeyCode::KP3:
    os << "KeyPad 3";
    break;
  case KeyCode::KP4:
    os << "KeyPad 4";
    break;
  case KeyCode::KP5:
    os << "KeyPad 5";
    break;
  case KeyCode::KP6:
    os << "KeyPad 6";
    break;
  case KeyCode::KP7:
    os << "KeyPad 7";
    break;
  case KeyCode::KP8:
    os << "KeyPad 8";
    break;
  case KeyCode::KP9:
    os << "KeyPad 9";
    break;
  case KeyCode::KPDecimal:
    os << "KeyPad .";
    break;
  case KeyCode::KPDivide:
    os << "KeyPad /";
    break;
  case KeyCode::KPMultiply:
    os << "KeyPad *";
    break;
  case KeyCode::KPSubtract:
    os << "KeyPad -";
    break;
  case KeyCode::KPAdd:
    os << "KeyPad +";
    break;
  case KeyCode::KPEnter:
    os << "KeyPad Enter";
    break;
  case KeyCode::KPEqual:
    os << "KeyPad =";
    break;
  case KeyCode::LeftShift:
    os << "Left Shift";
    break;
  case KeyCode::LeftControl:
    os << "Left Control";
    break;
  case KeyCode::LeftAlt:
    os << "Left Alt";
    break;
  case KeyCode::LeftSuper:
    os << "Left Super";
    break;
  case KeyCode::RightShift:
    os << "Right Shift";
    break;
  case KeyCode::RightControl:
    os << "Right Control";
    break;
  case KeyCode::RightAlt:
    os << "Right Alt";
    break;
  case KeyCode::RightSuper:
    os << "Right Super";
    break;
  case KeyCode::Menu:
    os << "Menu";
    break;
  default:
    break;
  }
  return os;
}

bool IsLetterKey(const KeyCode aKeyCode);
} // namespace EventSystem
} // namespace Kara