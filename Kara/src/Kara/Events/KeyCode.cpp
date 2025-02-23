#include "pch.hpp"

#include "KeyCode.hpp"

namespace Kara {
namespace Events {
bool IsLetterKey(const KeyCode aKeyCode) {
  switch (aKeyCode) {
  case KeyCode::A:
  case KeyCode::B:
  case KeyCode::C:
  case KeyCode::D:
  case KeyCode::E:
  case KeyCode::F:
  case KeyCode::G:
  case KeyCode::H:
  case KeyCode::I:
  case KeyCode::J:
  case KeyCode::K:
  case KeyCode::L:
  case KeyCode::M:
  case KeyCode::N:
  case KeyCode::O:
  case KeyCode::P:
  case KeyCode::Q:
  case KeyCode::R:
  case KeyCode::S:
  case KeyCode::T:
  case KeyCode::U:
  case KeyCode::V:
  case KeyCode::W:
  case KeyCode::X:
  case KeyCode::Y:
  case KeyCode::Z:
    return true;

  default:
    return false;
  }
}

} // namespace Events
} // namespace Kara