#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

uniform float u_Time;
uniform mat4 u_MVP;

out vec2 v_TexCoord;

void main(){
    gl_Position = u_MVP * vec4(position, 1.0);
    v_TexCoord = texCoord;
}