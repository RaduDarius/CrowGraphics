#pragma once

#include "Kara/EventSystem/KeyCode.hpp"
#include "Kara/EventSystem/MouseButtonId.hpp"

#include <imgui.h>

namespace Kara {
namespace EventSystem {
//! Functions that should convert between different types of key codes.
KeyCode ConvertToKeyCode(const int aKeyCode);

ImGuiKey ConvertToImGuiKey(const KeyCode aKeyCode);
int ConvertToGlfwCode(const KeyCode aKeyCode);

//! Functions that should convert between different types of mouse button codes.
MouseButtonId ConvertToMouseButtonId(const int aButton);
int ConvertToGlfwButton(const MouseButtonId aMouseButton);

} // namespace EventSystem
} // namespace Kara