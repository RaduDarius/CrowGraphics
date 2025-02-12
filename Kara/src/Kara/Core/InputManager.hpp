#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/EventSystem/KeyCode.hpp"
#include "Kara/EventSystem/MouseButtonId.hpp"

namespace Kara {
namespace Core {
namespace InputManager {
std::pair<float, float> GetMousePos();
inline float GetMouseX() { return GetMousePos().first; }
inline float GetMouseY() { return GetMousePos().second; }

bool IsKeyPressed(const EventSystem::KeyCode aKeyCode);
bool IsMouseButtonPressed(const EventSystem::MouseButtonId aButtonId);
} // namespace InputManager
} // namespace Core
} // namespace Kara