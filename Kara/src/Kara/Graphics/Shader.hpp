#pragma once

#include <glm/glm.hpp>

#include <string_view>

namespace Kara {
namespace Graphics {
class Shader {
public:
  enum class Type { Basic, Texture };

  Shader(const Type aType) : mShaderType{aType} {}
  virtual ~Shader() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  virtual void UploadUniformMat4(const std::string_view &aName,
                                 const glm::mat4 &aMat) = 0;
  virtual void UploadUniformVec4(const std::string_view &aName,
                                 const glm::vec4 &aVec) = 0;
  virtual void UploadUniformInt(const std::string_view &aName,
                                const unsigned int aInt) = 0;

protected:
  inline Type GetType() const { return mShaderType; }

private:
  Type mShaderType;
};

} // namespace Graphics
} // namespace Kara