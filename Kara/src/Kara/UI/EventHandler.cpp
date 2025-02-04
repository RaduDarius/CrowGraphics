#include "pch.hpp"

#include "EventHandler.hpp"

#include "Kara/EventSystem/Convertors.hpp"
#include "Kara/EventSystem/Dispatcher.hpp"
#include "Kara/EventSystem/KeyCode.hpp"
#include "Kara/EventSystem/MouseButtonId.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Kara {
namespace UI {
namespace {
#define SET_SPECIAL_KEY_PIN(x)                                                 \
  io.Key##x = ImGui::IsKeyPressed(ImGuiKey_Left##x) ||                         \
              ImGui::IsKeyPressed(ImGuiKey_Right##x);

} // namespace

void EventHandler::OnEvent(EventSystem::Event &aEvent) {
  EventSystem::Dispatcher dispatcher{aEvent};

  dispatcher.Dispatch<EventSystem::MouseButtonPressedEvent>(
      [&](EventSystem::MouseButtonPressedEvent &aEvent) {
        return OnMouseButtonPressedEvent(aEvent);
      });

  dispatcher.Dispatch<EventSystem::MouseButtonReleasedEvent>(
      [&](EventSystem::MouseButtonReleasedEvent &aEvent) {
        return OnMouseButtonReleasedEvent(aEvent);
      });

  dispatcher.Dispatch<EventSystem::MouseMovedEvent>(
      [&](EventSystem::MouseMovedEvent &aEvent) {
        return OnMouseMovedEvent(aEvent);
      });

  dispatcher.Dispatch<EventSystem::MouseScrolledEvent>(
      [&](EventSystem::MouseScrolledEvent &aEvent) {
        return OnMouseScrolledEvent(aEvent);
      });

  dispatcher.Dispatch<EventSystem::KeyPressedEvent>(
      [&](EventSystem::KeyPressedEvent &aEvent) {
        return OnKeyPressedEvent(aEvent);
      });

  dispatcher.Dispatch<EventSystem::KeyReleasedEvent>(
      [&](EventSystem::KeyReleasedEvent &aEvent) {
        return OnKeyReleasedEvent(aEvent);
      });

  dispatcher.Dispatch<EventSystem::KeyTypedEvent>(
      [&](EventSystem::KeyTypedEvent &aEvent) {
        return OnKeyTypedEvent(aEvent);
      });

  dispatcher.Dispatch<EventSystem::WindowResizedEvent>(
      [&](EventSystem::WindowResizedEvent &aEvent) {
        return OnWindowResizedEvent(aEvent);
      });
}

bool EventHandler::OnMouseButtonPressedEvent(
    EventSystem::MouseButtonPressedEvent &aEvent) {
  auto &io = ImGui::GetIO();
  io.AddMouseButtonEvent(EventSystem::ConvertToGlfwButton(aEvent.GetButton()),
                         true);

  return false;
}

bool EventHandler::OnMouseButtonReleasedEvent(
    EventSystem::MouseButtonReleasedEvent &aEvent) {
  auto &io = ImGui::GetIO();
  io.AddMouseButtonEvent(EventSystem::ConvertToGlfwButton(aEvent.GetButton()),
                         false);

  return false;
}

bool EventHandler::OnMouseMovedEvent(EventSystem::MouseMovedEvent &aEvent) {
  auto &io = ImGui::GetIO();
  io.AddMousePosEvent(aEvent.GetX(), aEvent.GetY());

  return false;
}

bool EventHandler::OnMouseScrolledEvent(
    EventSystem::MouseScrolledEvent &aEvent) {
  auto &io = ImGui::GetIO();
  io.AddMouseWheelEvent(aEvent.GetXOffset(), aEvent.GetYOffset());

  return false;
}

bool EventHandler::OnKeyPressedEvent(EventSystem::KeyPressedEvent &aEvent) {
  auto &io = ImGui::GetIO();
  auto key = EventSystem::ConvertToImGuiKey(aEvent.GetKeyCode());
  io.AddKeyEvent(key, true);

  SET_SPECIAL_KEY_PIN(Ctrl)
  SET_SPECIAL_KEY_PIN(Shift)
  SET_SPECIAL_KEY_PIN(Alt)
  SET_SPECIAL_KEY_PIN(Super)

  return false;
}

bool EventHandler::OnKeyReleasedEvent(EventSystem::KeyReleasedEvent &aEvent) {
  auto &io = ImGui::GetIO();
  auto key = EventSystem::ConvertToImGuiKey(aEvent.GetKeyCode());
  io.AddKeyEvent(key, false);

  return false;
}

bool EventHandler::OnKeyTypedEvent(EventSystem::KeyTypedEvent &aEvent) {
  auto &io = ImGui::GetIO();
  if (EventSystem::IsLetterKey(aEvent.GetKeyCode())) {
    io.AddInputCharacter(EventSystem::ConvertToImGuiKey(aEvent.GetKeyCode()));
  }
  return false;
}

bool EventHandler::OnWindowResizedEvent(
    EventSystem::WindowResizedEvent &aEvent) {
  auto &io = ImGui::GetIO();
  io.DisplaySize = ImVec2{aEvent.GetWidth(), aEvent.GetHeight()};
  io.DisplayFramebufferScale = ImVec2{1.0f, 1.0f};

  glViewport(0, 0, aEvent.GetWidth(), aEvent.GetHeight());

  return false;
}

} // namespace UI
} // namespace Kara