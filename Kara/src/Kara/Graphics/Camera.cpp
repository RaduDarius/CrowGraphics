#include "pch.hpp"

#include "Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace Kara {
namespace Graphics {
Camera::Camera(const float aLeftCorner, const float aRightCorner,
               const float aBottomCorner, const float aTopCorner)
    : mProjectionMatrix{glm::ortho(aLeftCorner, aRightCorner, aBottomCorner,
                                   aTopCorner, -1.0f, 1.0f)} {
  mVPMatrix = mProjectionMatrix * mViewMatrix;
}

void Camera::AddPosition(const glm::vec3 &aOther) {
  mPosition += aOther;
  ComputeViewMatrix();
}

void Camera::AddRotation(const float aOther) {
  mRotation += aOther;
  ComputeViewMatrix();
}

void Camera::ComputeViewMatrix() {
  auto transform = glm::translate(glm::mat4(1.0f), mPosition);
  transform =
      glm::rotate(transform, glm::radians(mRotation), glm::vec3(0, 0, 1));

  mViewMatrix = glm::inverse(transform);
  mVPMatrix = mProjectionMatrix * mViewMatrix;
}

} // namespace Graphics
} // namespace Kara
