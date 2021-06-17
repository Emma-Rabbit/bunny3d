#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

uniform float u_Time;

out vec2 v_TexCoord;

void main(){
    gl_Position = vec4(sin(position.x+u_Time), sin(position.y+u_Time), position.z, position.w);
    v_TexCoord = texCoord;
}