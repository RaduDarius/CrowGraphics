#version 330 core

layout (location = 0) out vec4 outColor;

in vec2 vTextCoord;

uniform sampler2D uTexture;

void main() {
    outColor = texture(uTexture, vTextCoord);
}