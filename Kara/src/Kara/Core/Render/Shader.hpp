#pragma once

#include <glm/glm.hpp>

#include <string_view>

namespace Kara {
namespace Core {
namespace Render {
class Shader {
public:
  virtual ~Shader() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  virtual void UploadUniformMat4(const std::string_view &aName,
                                 const glm::mat4 &aMat) = 0;
  virtual void UploadUniformVec4(const std::string_view &aName,
                                 const glm::vec4 &aVec) = 0;
};

} // namespace Render
} // namespace Core
} // namespace Kara