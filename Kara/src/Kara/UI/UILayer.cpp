#include "pch.hpp"

#include "UILayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/EventSystem/Dispatcher.hpp"
#include "Kara/EventSystem/KeyEvent.hpp"
#include "Kara/EventSystem/MouseEvent.hpp"
#include "Kara/EventSystem/WindowEvent.hpp"

#include "Platform/OpenGL/imgui_impl_opengl3.hpp"

#include "imgui.h"
#include "GLFW/glfw3.h"

namespace Kara {
namespace UI {
namespace {
// TODO: We should make a system to set externaly through a config file.
constexpr auto OpenGL3Version{"#version 410"};
} // namespace

UILayer::UILayer() : LayerSystem::Layer{"UI Layer"} {}

UILayer::~UILayer() {}

void UILayer::OnAttach() {
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  auto &io = ImGui::GetIO();
  io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
  io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

  ImGui_ImplOpenGL3_Init(OpenGL3Version);
}

void UILayer::OnDetach() {}

void UILayer::OnUpdate() {
  auto &io = ImGui::GetIO();

  const auto size = Application::Get()->GetWindowSize();
  io.DisplaySize = {static_cast<float>(size.mWidth),
                    static_cast<float>(size.mHeight)};
  io.DeltaTime = GetDeltaTime();

  ImGui_ImplOpenGL3_NewFrame();
  ImGui::NewFrame();

  static bool show{true};
  ImGui::ShowDemoWindow(&show);

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UILayer::OnEvent(EventSystem::Event &aEvent) {
  mEventHandler.OnEvent(aEvent);
}

float UILayer::GetDeltaTime() {
  const auto time = glfwGetTime();
  const auto delta = mTime > 0.0f ? time - mTime : 1.0f / 60.0f;
  mTime = time;

  return delta;
}

} // namespace UI
} // namespace Kara