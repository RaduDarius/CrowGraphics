#include "pch.hpp"

#include "Shader.hpp"

#include "Kara/Log/Logger.hpp"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace Kara {
namespace Core {
namespace Render {
namespace {
//! @brief Relative to the parent. ".." IS INTENTIONAL DO NOT CHANGE IT.
constexpr auto VertexShaderPath{"../Kara/shaders/basic.vert"};
constexpr auto FragmentShaderPath{"../Kara/shaders/basic.frag"};
} // namespace

Shader::Shader() {
  mShaderProgram = glCreateProgram();
  const auto vertShaderPath =
      std::filesystem::current_path().append(VertexShaderPath);
  auto vertShader = CreateShader(vertShaderPath, GL_VERTEX_SHADER);

  const auto fragShaderPath =
      std::filesystem::current_path().append(FragmentShaderPath);
  auto fragShader = CreateShader(fragShaderPath, GL_FRAGMENT_SHADER);

  LinkShader(mShaderProgram);

  // Cleanup shaders
  glDeleteShader(vertShader);
  glDeleteShader(fragShader);
}

void Shader::Bind() { glUseProgram(mShaderProgram); }

void Shader::AddProjectionMat(const glm::mat4 &aProjectionMatrix) {
  glUseProgram(mShaderProgram);
  int projLoc = glGetUniformLocation(mShaderProgram, "projection");

  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(aProjectionMatrix));
}

//! @brief Caller should delete the shader after use.
unsigned int Shader::CreateShader(const std::filesystem::path &aPath,
                                  const int aType) {
  const auto shaderStr = ReadShaderFile(aPath);
  const auto shaderSource = shaderStr.c_str();

  GLuint shader = glCreateShader(aType);
  glShaderSource(shader, 1, &shaderSource, NULL);
  glCompileShader(shader);

  int success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  KARA_CORE_ASSERT(success, "Shader Compilation Failed");

  glAttachShader(mShaderProgram, shader);

  return shader;
}

void Shader::LinkShader(const unsigned int aShader) {
  glLinkProgram(mShaderProgram);

  int success;
  glGetProgramiv(aShader, GL_LINK_STATUS, &success);
  KARA_CORE_ASSERT(success, "Shader Program Linking Failed");
}

std::string Shader::ReadShaderFile(const std::filesystem::path &aPath) {
  std::ifstream shaderFile(aPath);

  std::stringstream buffer;
  buffer << shaderFile.rdbuf();
  return buffer.str();
}

} // namespace Render
} // namespace Core
} // namespace Kara