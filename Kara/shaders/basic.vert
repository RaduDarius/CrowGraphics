#version 330 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec4 inColor;

uniform mat4 projection;

out vec4 vColor;

void main() {
    vColor = inColor;
    gl_Position = projection * vec4(inPosition, 1.0f);
}