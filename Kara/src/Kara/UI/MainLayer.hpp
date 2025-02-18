#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Render/Camera.hpp"
#include "Kara/EventSystem/Event.hpp"
#include "Kara/LayerSystem/Layer.hpp"
#include "Kara/UI/Core/ComponentManager.hpp"

#include <memory>

namespace Kara {
namespace UI {
class MainLayer : public LayerSystem::Layer {
public:
  MainLayer();

  void OnAttach() override;
  void OnRender() override;
  void OnUpdate() override;

private:
  Kara::Core::Render::Camera mCamera;
  // Kara::Core::Scope<UI::Core::ComponentManager> mComponentManager;
  Kara::Core::Scope<Kara::Core::Render::Renderer> mRenderer;

  Kara::Core::Ref<Kara::Core::Render::Shader> mShader;
  Kara::Core::Ref<Kara::Core::Render::VertexArray> mVertexArray;

  // Camera spec
  float mCameraMoveSpeed{10.0f};
  float mCameraRotationSpeed{10.0f};
  float mObjMoveSpeed{10.0f};
  float mObjRotationSpeed{10.0f};
  glm::vec4 mColor{0.0f, 0.0f, 1.0f, 1.0f};
  glm::vec3 mPosition{0.0f};
  float mRotation{0.0f};
};
} // namespace UI
} // namespace Kara