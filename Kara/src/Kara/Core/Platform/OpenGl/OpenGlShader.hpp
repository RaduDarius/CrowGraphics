#pragma once

#include "Kara/Core/Render/Shader.hpp"

#include <glm/glm.hpp>

#include <filesystem>
#include <string>

namespace Kara {
namespace Core {
namespace Platform {
class OpenGlShader : public Render::Shader {
public:
  OpenGlShader();
  ~OpenGlShader() override;

  void Bind() const override;
  void Unbind() const override;

  void UploadUniformMat4(const std::string_view &aName,
                         const glm::mat4 &aMat) override;
  void UploadUniformVec4(const std::string_view &aName,
                         const glm::vec4 &aVec) override;

private:
  unsigned int CreateShader(const std::filesystem::path &aPath,
                            const int aType);
  void LinkShader(const unsigned int aShader);

  std::string ReadShaderFile(const std::filesystem::path &aPath);

  uint32_t mRendererId;
};
} // namespace Platform
} // namespace Core
} // namespace Kara