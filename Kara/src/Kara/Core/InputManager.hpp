#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/EventSystem/KeyCode.hpp"
#include "Kara/EventSystem/MouseButtonId.hpp"

namespace Kara {
namespace Core {
namespace InputManager {
std::pair<float, float> KARA_API GetMousePos();
inline float KARA_API GetMouseX() { return GetMousePos().first; }
inline float KARA_API GetMouseY() { return GetMousePos().second; }

bool KARA_API IsKeyPressed(const EventSystem::KeyCode aKeyCode);
bool KARA_API IsMouseButtonPressed(const EventSystem::MouseButtonId aButtonId);
} // namespace InputManager
} // namespace Core
} // namespace Kara