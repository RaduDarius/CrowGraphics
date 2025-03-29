#version 330 core

in vec2 vTextCoord;
out vec4 FragColor;

uniform sampler2D uTexture;  
uniform vec4 uTextColor;

void main() {
    float alpha = texture(uTexture, vTextCoord).r;
    FragColor = vec4(uTextColor.xyz, uTextColor.a * alpha); 
}