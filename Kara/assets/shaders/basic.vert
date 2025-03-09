#version 330 core

layout (location = 0) in vec3 inPosition;

uniform mat4 uVP;
uniform mat4 uModel;

void main() {
    gl_Position = uVP * uModel * vec4(inPosition, 1.0f);
}