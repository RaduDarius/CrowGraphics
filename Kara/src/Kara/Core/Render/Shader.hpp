#pragma once

#include <glm/glm.hpp>

#include <filesystem>
#include <string>

namespace Kara {
namespace Core {
namespace Render {
class Shader {
public:
  Shader();

  void Bind();

  void AddProjectionMat(const glm::mat4 &aProjectionMatrix);

private:
  unsigned int CreateShader(const std::filesystem::path &aPath,
                            const int aType);
  void LinkShader(const unsigned int aShader);

  std::string ReadShaderFile(const std::filesystem::path &aPath);

  unsigned int mShaderProgram;
};
} // namespace Render
} // namespace Core
} // namespace Kara