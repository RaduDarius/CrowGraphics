#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Events/Event.hpp"
#include "Kara/Graphics/Camera.hpp"
#include "Kara/Graphics/FontTexture.hpp"
#include "Kara/Graphics/Shader.hpp"
#include "Kara/Graphics/Texture.hpp"
#include "Kara/Graphics/VertexArray.hpp"
#include "Kara/Layers/Layer.hpp"

#include <memory>

namespace Kara {
namespace UI {
class TestLayer : public Layers::Layer {
public:
  TestLayer();

  void OnRender() override;
  void OnUpdate() override;

private:
  Graphics::Camera mCamera;

  Core::Ref<Graphics::Shader> mShader;
  Core::Ref<Graphics::Shader> mTextureShader;
  Core::Ref<Graphics::Shader> mFontShader;
  Core::Ref<Graphics::Texture> mTexture;
  Core::Ref<Graphics::FontTexture> mFontTexture;

  Core::Ref<Graphics::VertexArray> mVertexArray;

  // Camera spec
  float mCameraMoveSpeed{10.0f};
  float mCameraRotationSpeed{10.0f};
  float mObjMoveSpeed{10.0f};
  float mObjRotationSpeed{10.0f};
  glm::vec4 mColor{0.0f, 0.0f, 1.0f, 1.0f};
  glm::vec3 mPosition{0.0f};
  glm::vec3 mCenter{50.f, 50.f, 0.0f};
  float mRotation{0.0f};
};
} // namespace UI
} // namespace Kara