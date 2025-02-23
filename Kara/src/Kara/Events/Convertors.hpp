#pragma once

#include "Kara/Events/KeyCode.hpp"
#include "Kara/Events/MouseButtonId.hpp"

#include <imgui.h>

namespace Kara {
namespace Events {
//! Functions that should convert between different types of key codes.
KeyCode ConvertToKeyCode(const int aKeyCode);

ImGuiKey ConvertToImGuiKey(const KeyCode aKeyCode);
int ConvertToGlfwCode(const KeyCode aKeyCode);

//! Functions that should convert between different types of mouse button codes.
MouseButtonId ConvertToMouseButtonId(const int aButton);
int ConvertToGlfwButton(const MouseButtonId aMouseButton);

} // namespace Events
} // namespace Kara