#include "pch.hpp"

#include "TestLayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/Core/Core.hpp"
#include "Kara/Core/InputManager.hpp"
#include "Kara/Font/FontFace.hpp"
#include "Kara/Graphics/RenderCommand.hpp"
#include "Kara/Graphics/Renderer.hpp"
#include "Kara/Log/Logger.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>

namespace Kara {
namespace UI {
TestLayer::TestLayer()
    : Layers::Layer{"Test Layer"},
      mCamera{Graphics::Camera{
          0.0f, static_cast<float>(Application::Get()->GetWindow()->GetWidth()),
          static_cast<float>(Application::Get()->GetWindow()->GetHeight()),
          0.0f}} {
  mVertexArray = Graphics::Renderer::CreateVertexArray();

  float vertices[] = {// Position 0
                      0.0f, 0.0f, 0.0f,
                      // Text Coordinates 0
                      0.0f, 0.0f,
                      // Position 1
                      100.0f, 0.0f, 0.0f,
                      // Text Coordinates 1
                      1.0f, 0.0f,
                      // Position 2
                      100.0f, 100.0f, 0.0f,
                      // Text Coordinates 2
                      1.0f, 1.0f,
                      // Position 3
                      0.0f, 100.0f, 0.0f,
                      // Text Coordinates
                      0.0f, 1.0f};

  Core::Ref<Graphics::VertexBuffer> vertexBuffer;
  vertexBuffer =
      Graphics::Renderer::CreateVertexBuffer(vertices, sizeof(vertices));

  Graphics::BufferLayout layout = {
      {Graphics::BufferElementType::Float3, "inPosition"},
      {Graphics::BufferElementType::Float2, "inTextCoord"},
  };
  vertexBuffer->SetLayout(layout);

  mVertexArray->AddVertexBuffer(vertexBuffer);

  uint32_t indeces[] = {0, 1, 2, 2, 3, 0};
  Core::Ref<Graphics::IndexBuffer> indexBuffer;
  indexBuffer = Graphics::Renderer::CreateIndexBuffer(indeces, sizeof(indeces));
  mVertexArray->AddIndexBuffer(indexBuffer);

  mShader = Graphics::Renderer::CreateShader(Graphics::Shader::Type::Basic);
  mTextureShader =
      Graphics::Renderer::CreateShader(Graphics::Shader::Type::Texture);
  mFontShader = Graphics::Renderer::CreateShader(Graphics::Shader::Type::Font);

  // mTexture = Graphics::Renderer::CreateTexture(
  //    "../Kara/assets/textures/texture_test_2.jpg");
  // mTexture->Unbind();
  mFontTexture = Graphics::Renderer::CreateFontTexture(Font::Handle::Arial);
}

void TestLayer::OnRender() {
  ImGui::ColorEdit3("Color", glm::value_ptr(mColor));

  ImGui::DragFloat3("Position", &mPosition.x);
  ImGui::DragFloat("Rotation", &mRotation, 1.0f, -180.0f, 180.0f);

  ImGui::DragFloat("Camera move Speed", &mCameraMoveSpeed);
  ImGui::DragFloat("Camera rotation Speed", &mCameraRotationSpeed);
  ImGui::DragFloat("Object move Speed", &mObjMoveSpeed);
  ImGui::DragFloat("Object rotation Speed", &mObjRotationSpeed);
}

void TestLayer::OnUpdate() {
  if (Core::InputManager::IsKeyPressed(Events::KeyCode::I)) {
    mCamera.AddPosition({0.0f, -mCameraMoveSpeed, 0.0f});
  } else if (Core::InputManager::IsKeyPressed(Events::KeyCode::K)) {
    mCamera.AddPosition({0.0f, mCameraMoveSpeed, 0.0f});
  }

  if (Core::InputManager::IsKeyPressed(Events::KeyCode::L)) {
    mCamera.AddPosition({mCameraMoveSpeed, 0.0f, 0.0f});
  } else if (Core::InputManager::IsKeyPressed(Events::KeyCode::J)) {
    mCamera.AddPosition({-mCameraMoveSpeed, 0.0f, 0.0f});
  }

  if (Core::InputManager::IsKeyPressed(Events::KeyCode::U)) {
    mCamera.AddRotation(-mCameraRotationSpeed);
  } else if (Core::InputManager::IsKeyPressed(Events::KeyCode::O)) {
    mCamera.AddRotation(mCameraRotationSpeed);
  }

  if (Core::InputManager::IsKeyPressed(Events::KeyCode::W)) {
    mPosition.y -= mObjMoveSpeed;
  } else if (Core::InputManager::IsKeyPressed(Events::KeyCode::S)) {
    mPosition.y += mObjMoveSpeed;
  }

  if (Core::InputManager::IsKeyPressed(Events::KeyCode::D)) {
    mPosition.x += mObjMoveSpeed;
  } else if (Core::InputManager::IsKeyPressed(Events::KeyCode::A)) {
    mPosition.x -= mObjMoveSpeed;
  }

  if (Core::InputManager::IsKeyPressed(Events::KeyCode::Q)) {
    mRotation -= mObjRotationSpeed;
  } else if (Core::InputManager::IsKeyPressed(Events::KeyCode::E)) {
    mRotation += mObjRotationSpeed;
  }

  auto transform = glm::translate(glm::mat4(1.0f), mPosition);
  transform = glm::translate(transform, mCenter);
  transform =
      glm::rotate(transform, glm::radians(mRotation), glm::vec3(0, 0, 1));
  transform = glm::translate(transform, -mCenter);

  mFontTexture->Bind();
  mFontShader->Bind();
  mFontShader->UploadUniformMat4("uVP", mCamera.GetVPMat());
  mFontShader->UploadUniformMat4("uModel", transform);
  mFontShader->UploadUniformInt("uTexture", 0);
  mFontShader->UploadUniformVec4("uTextColor",
                                 glm::vec4(0.0f, 1.0f, 0.0f, .5f));

  // mTextureShader->UploadUniformVec4("uColor", mColor);

  mVertexArray->Bind();
  Graphics::RenderCommand::Draw(mVertexArray);

  mFontShader->Unbind();
  mFontTexture->Unbind();
}

} // namespace UI
} // namespace Kara