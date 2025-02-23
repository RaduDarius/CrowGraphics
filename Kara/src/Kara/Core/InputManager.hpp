#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Events/KeyCode.hpp"
#include "Kara/Events/MouseButtonId.hpp"

namespace Kara {
namespace Core {
namespace InputManager {
std::pair<float, float> GetMousePos();
inline float GetMouseX() { return GetMousePos().first; }
inline float GetMouseY() { return GetMousePos().second; }

bool IsKeyPressed(const Events::KeyCode aKeyCode);
bool IsMouseButtonPressed(const Events::MouseButtonId aButtonId);
} // namespace InputManager
} // namespace Core
} // namespace Kara
