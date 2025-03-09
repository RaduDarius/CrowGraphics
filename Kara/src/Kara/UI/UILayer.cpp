#include "pch.hpp"

#include "UILayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/Events/KeyEvent.hpp"
#include "Kara/Events/MouseEvent.hpp"
#include "Kara/Events/WindowEvent.hpp"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Kara {
namespace UI {
namespace {
// TODO: We should make a system to set externaly through a config file.
constexpr auto OpenGL3Version{"#version 410"};
} // namespace

UILayer::UILayer() : Layers::Layer{"UI Layer"} {}

void UILayer::OnAttach() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  auto &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  auto &style = ImGui::GetStyle();
  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    style.WindowRounding = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }

  auto window = static_cast<GLFWwindow *>(
      Application::Get()->GetWindow()->GetNativeWindow());

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(OpenGL3Version);
}

void UILayer::OnDetach() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void UILayer::OnRender() {
  static bool show{true};
  ImGui::ShowDemoWindow(&show);
}

void UILayer::Begin() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void UILayer::End() {
  auto &io = ImGui::GetIO();
  auto windowSize = Application::Get()->GetWindowSize();

  io.DisplaySize = ImVec2(static_cast<float>(windowSize.Width),
                          static_cast<float>(windowSize.Height));

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
  }
  auto backupCurrentContext = glfwGetCurrentContext();
  ImGui::UpdatePlatformWindows();
  ImGui::RenderPlatformWindowsDefault();
  glfwMakeContextCurrent(backupCurrentContext);
}

} // namespace UI
} // namespace Kara