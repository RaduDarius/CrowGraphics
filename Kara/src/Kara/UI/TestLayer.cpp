#include "pch.hpp"

#include "TestLayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/Core/Core.hpp"
#include "Kara/Core/InputManager.hpp"
#include "Kara/Graphics/Command.hpp"
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
  mRenderer.reset(new Graphics::Renderer(Graphics::RenderApi::OpenGl));

  mVertexArray = mRenderer->CreateVertexArray();

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
  vertexBuffer = mRenderer->CreateVertexBuffer(vertices, sizeof(vertices));

  Graphics::BufferLayout layout = {
      {Graphics::BufferElementType::Float3, "inPosition"},
      {Graphics::BufferElementType::Float2, "inTextCoord"},
  };
  vertexBuffer->SetLayout(layout);

  mVertexArray->AddVertexBuffer(vertexBuffer);

  uint32_t indeces[] = {0, 1, 2, 2, 3, 0};
  Core::Ref<Graphics::IndexBuffer> indexBuffer;
  indexBuffer = mRenderer->CreateIndexBuffer(indeces, sizeof(indeces));
  mVertexArray->AddIndexBuffer(indexBuffer);

  mShader = mRenderer->CreateShader(Graphics::Shader::Type::Basic);
  mTextureShader = mRenderer->CreateShader(Graphics::Shader::Type::Texture);

  mTexture =
      mRenderer->CreateTexture("../Kara/assets/textures/texture_test_2.jpg");
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

  mTexture->Bind();
  mTextureShader->Bind();
  mTextureShader->UploadUniformMat4("uVP", mCamera.GetVPMat());
  mTextureShader->UploadUniformMat4("uModel", transform);
  mTextureShader->UploadUniformInt("uTexture", 1);

  // mTextureShader->UploadUniformVec4("uColor", mColor);

  mVertexArray->Bind();
  Graphics::Command::Draw(mVertexArray);
}

} // namespace UI
} // namespace Kara