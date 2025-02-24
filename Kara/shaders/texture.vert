#version 330 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inTextCoord;

uniform mat4 uVP;
uniform mat4 uModel;

out vec2 vTextCoord;

void main() {
    vTextCoord = inTextCoord;
    gl_Position = uVP * uModel * vec4(inPosition, 1.0f);
}