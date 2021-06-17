#version 330 core

uniform float u_Time;
uniform sampler2D u_Texture;

layout(location = 0) out vec4 color; // variable that outputs final color

in vec2 v_TexCoord;

void main(){
    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = texColor + vec4(0.8f, 0.2f, 0.2f, 1.0f);
}