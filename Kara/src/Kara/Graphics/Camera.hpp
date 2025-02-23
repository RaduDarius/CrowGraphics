#pragma once

#include <glm/glm.hpp>

namespace Kara {
namespace Graphics {
//! @brief Ortographic camera for now, becasue we want only 2D elements at the
//! moment.
//! TODO: Update camera system to support 3D scenes
class Camera {
public:
  Camera(const float aLeftCorner, const float aRightCorner,
         const float aBottomCorner, const float aTopCorner);

  void AddPosition(const glm::vec3 &aOther);
  void AddRotation(const float aOther);

  inline const glm::mat4 &GetProjectionMat() const { return mProjectionMatrix; }
  inline const glm::mat4 &GetViewMat() const { return mViewMatrix; }
  inline const glm::mat4 &GetVPMat() const { return mVPMatrix; }

private:
  void ComputeViewMatrix();

  glm::mat4 mProjectionMatrix;
  glm::mat4 mViewMatrix{1.0f};
  glm::mat4 mVPMatrix;

  glm::vec3 mPosition{0.0f};
  float mRotation{0.0f};
};
} // namespace Graphics
} // namespace Kara
