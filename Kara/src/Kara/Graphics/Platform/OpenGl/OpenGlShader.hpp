#pragma once

#include "Kara/Graphics/Shader.hpp"

#include <glm/glm.hpp>

#include <filesystem>
#include <string>
#include <utility>

namespace Kara {
namespace Graphics {
class OpenGlShader : public Shader {
public:
  OpenGlShader(const Type aType);
  ~OpenGlShader() override;

  void Bind() const override;
  void Unbind() const override;

  void UploadUniformMat4(const std::string_view &aName,
                         const glm::mat4 &aMat) override;
  void UploadUniformVec4(const std::string_view &aName,
                         const glm::vec4 &aVec) override;
  void UploadUniformInt(const std::string_view &aName,
                        const unsigned int aInt) override;

private:
  unsigned int CreateShader(const std::filesystem::path &aPath,
                            const int aType);
  //! @brief Used to retrieve the path to the vertex and fragment shaders based
  //! on the shader type.
  //! @return [vert, frag] shader paths
  std::pair<std::string_view, std::string_view> GetShaderPaths() const;
  void LinkShader(const unsigned int aShader);

  std::string ReadShaderFile(const std::filesystem::path &aPath);

  uint32_t mRendererId;
};
} // namespace Graphics
} // namespace Kara
