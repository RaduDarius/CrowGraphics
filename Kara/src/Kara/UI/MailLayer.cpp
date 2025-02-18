#include "pch.hpp"

#include "MainLayer.hpp"

#include "Kara/Application.hpp"
#include "Kara/Core/Core.hpp"
#include "Kara/Core/InputManager.hpp"
#include "Kara/Core/Render/Command.hpp"
#include "Kara/Log/Logger.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "imgui.h"

namespace Kara {
namespace UI {
using namespace Kara::Core;

MainLayer::MainLayer()
    : LayerSystem::Layer{"Main Layer"},
      mCamera{Render::Camera{
          0.0f, static_cast<float>(Application::Get()->GetWindow()->GetWidth()),
          static_cast<float>(Application::Get()->GetWindow()->GetHeight()),
          0.0f}} {
  mRenderer.reset(new Render::Renderer(Render::RenderApi::OpenGl));

  mVertexArray.reset(mRenderer->CreateVertexArray());

  float vertices[] = {// Position 0
                      0.0f, 0.0f, 0.0f,
                      // Position 1
                      100.0f, 0.0f, 0.0f,
                      // Position 2
                      100.0f, 100.0f, 0.0f,
                      // Position 3
                      0.0f, 100.0f, 0.0f};

  Ref<Render::VertexBuffer> vertexBuffer;
  vertexBuffer.reset(mRenderer->CreateVertexBuffer(vertices, sizeof(vertices)));

  Render::BufferLayout layout = {
      {Render::BufferElementType::Float3, "inPosition"},
  };
  vertexBuffer->SetLayout(layout);

  mVertexArray->AddVertexBuffer(vertexBuffer);

  uint32_t indeces[] = {0, 1, 2, 2, 3, 0};
  Ref<Render::IndexBuffer> indexBuffer;
  indexBuffer.reset(mRenderer->CreateIndexBuffer(indeces, sizeof(indeces)));
  mVertexArray->AddIndexBuffer(indexBuffer);

  mShader.reset(mRenderer->CreateShader());
}

void MainLayer::OnAttach() {
  // mComponentManager.reset(new UI::Core::ComponentManager());
}

void MainLayer::OnRender() {
  // mComponentManager->Render();
  ImGui::ColorEdit3("Color", glm::value_ptr(mColor));
}

void MainLayer::OnUpdate() {
  if (InputManager::IsKeyPressed(EventSystem::KeyCode::I)) {
    mCamera.AddPosition({0.0f, -mCameraMoveSpeed, 0.0f});
  } else if (InputManager::IsKeyPressed(EventSystem::KeyCode::K)) {
    mCamera.AddPosition({0.0f, mCameraMoveSpeed, 0.0f});
  }

  if (InputManager::IsKeyPressed(EventSystem::KeyCode::L)) {
    mCamera.AddPosition({mCameraMoveSpeed, 0.0f, 0.0f});
  } else if (InputManager::IsKeyPressed(EventSystem::KeyCode::J)) {
    mCamera.AddPosition({-mCameraMoveSpeed, 0.0f, 0.0f});
  }

  if (InputManager::IsKeyPressed(EventSystem::KeyCode::U)) {
    mCamera.AddRotation(-mCameraRotationSpeed);
  } else if (InputManager::IsKeyPressed(EventSystem::KeyCode::O)) {
    mCamera.AddRotation(mCameraRotationSpeed);
  }

  if (InputManager::IsKeyPressed(EventSystem::KeyCode::W)) {
    mPosition.y -= mObjMoveSpeed;
  } else if (InputManager::IsKeyPressed(EventSystem::KeyCode::S)) {
    mPosition.y += mObjMoveSpeed;
  }

  if (InputManager::IsKeyPressed(EventSystem::KeyCode::D)) {
    mPosition.x += mObjMoveSpeed;
  } else if (InputManager::IsKeyPressed(EventSystem::KeyCode::A)) {
    mPosition.x -= mObjMoveSpeed;
  }

  if (InputManager::IsKeyPressed(EventSystem::KeyCode::Q)) {
    mRotation -= mObjRotationSpeed;
  } else if (InputManager::IsKeyPressed(EventSystem::KeyCode::E)) {
    mRotation += mObjRotationSpeed;
  }

  auto transform = glm::translate(glm::mat4(1.0f), mPosition);
  transform =
      glm::rotate(transform, glm::radians(mRotation), glm::vec3(0, 0, 1));

  mShader->Bind();
  mShader->UploadUniformMat4("uVP", mCamera.GetVPMat());
  mShader->UploadUniformMat4("uModel", transform);
  mShader->UploadUniformVec4("uColor", mColor);

  mVertexArray->Bind();
  Render::Command::Draw(mVertexArray);
}

} // namespace UI
} // namespace Kara