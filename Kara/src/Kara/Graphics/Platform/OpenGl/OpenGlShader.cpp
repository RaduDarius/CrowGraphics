#include "pch.hpp"

#include "OpenGlShader.hpp"

#include "Kara/Log/Logger.hpp"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace Kara {
namespace Graphics {
namespace {
//! @brief Relative to the parent. ".." IS INTENTIONAL DO NOT CHANGE IT.
constexpr auto BasicVertexShaderPath{"../Kara/assets/shaders/basic.vert"};
constexpr auto BasicFragmentShaderPath{"../Kara/assets/shaders/basic.frag"};

constexpr auto TextureVertexShaderPath{"../Kara/assets/shaders/texture.vert"};
constexpr auto TextureFragmentShaderPath{"../Kara/assets/shaders/texture.frag"};

constexpr auto FontVertexShaderPath{"../Kara/assets/shaders/font.vert"};
constexpr auto FontFragmentShaderPath{"../Kara/assets/shaders/font.frag"};
} // namespace

OpenGlShader::OpenGlShader(const Type aType) : Shader{aType} {
  mRendererId = glCreateProgram();
  auto [vertPath, fragPath] = GetShaderPaths();

  const auto vertShaderPath = std::filesystem::current_path().append(vertPath);
  auto vertShader = CreateShader(vertShaderPath, GL_VERTEX_SHADER);

  const auto fragShaderPath = std::filesystem::current_path().append(fragPath);
  auto fragShader = CreateShader(fragShaderPath, GL_FRAGMENT_SHADER);

  LinkShader(mRendererId);

  // Cleanup shaders
  glDeleteShader(vertShader);
  glDeleteShader(fragShader);
}

OpenGlShader::~OpenGlShader() { glDeleteProgram(mRendererId); }

void OpenGlShader::Bind() const { glUseProgram(mRendererId); }

void OpenGlShader::Unbind() const { glUseProgram(0); }

void OpenGlShader::UploadUniformMat4(const std::string_view &aName,
                                     const glm::mat4 &aMat) {
  int location = glGetUniformLocation(mRendererId, aName.data());
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(aMat));
}

void OpenGlShader::UploadUniformVec4(const std::string_view &aName,
                                     const glm::vec4 &aVec) {
  int location = glGetUniformLocation(mRendererId, aName.data());
  glUniform4f(location, aVec.x, aVec.y, aVec.z, aVec.w);
}

void OpenGlShader::UploadUniformInt(const std::string_view &aName,
                                    const unsigned int aInt) {
  int location = glGetUniformLocation(mRendererId, aName.data());
  glUniform1i(location, aInt);
}

//! @brief Caller should delete the shader after use.
unsigned int OpenGlShader::CreateShader(const std::filesystem::path &aPath,
                                        const int aType) {
  const auto shaderStr = ReadShaderFile(aPath);
  const auto shaderSource = shaderStr.c_str();

  GLuint shader = glCreateShader(aType);
  glShaderSource(shader, 1, &shaderSource, NULL);
  glCompileShader(shader);

  int success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  KARA_CORE_ASSERT(success, "Shader Compilation Failed");

  glAttachShader(mRendererId, shader);

  return shader;
}

std::pair<std::string_view, std::string_view>
OpenGlShader::GetShaderPaths() const {
  switch (GetType()) {
  case Type::Font:
    return {FontVertexShaderPath, FontFragmentShaderPath};

  case Type::Texture:
    return {TextureVertexShaderPath, TextureFragmentShaderPath};

  case Type::Basic:
  default:
    return {BasicVertexShaderPath, BasicFragmentShaderPath};
  }
}

void OpenGlShader::LinkShader(const unsigned int aShader) {
  glLinkProgram(mRendererId);

  int success;
  glGetProgramiv(aShader, GL_LINK_STATUS, &success);
  KARA_CORE_ASSERT(success, "Shader Program Linking Failed");
}

std::string OpenGlShader::ReadShaderFile(const std::filesystem::path &aPath) {
  std::ifstream shaderFile(aPath);

  std::stringstream buffer;
  buffer << shaderFile.rdbuf();
  return buffer.str();
}

} // namespace Graphics
} // namespace Kara
