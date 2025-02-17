#pragma once

#include <glm/glm.hpp>

namespace Kara {
namespace Core {
namespace Render {
class Camera {
public:
  Camera(const float aLeftCorner, const float aRightCorner,
         const float aBottomCorner, const float aTopCorner);

private:
  glm::mat4x4 mProjectionMatrix;
  glm::mat4x4 mViewMatrix;

  glm::vec3 mPosition;
};
} // namespace Render
} // namespace Core
} // namespace Kara