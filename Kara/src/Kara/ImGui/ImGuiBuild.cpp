#include "pch.hpp"

//! Some hack to force the examples from ImGUI to be compiled staticly into our engine.
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "backends/imgui_impl_opengl3.cpp"
#include "backends/imgui_impl_glfw.cpp"