#version 330 core

uniform float u_Time;
uniform sampler2D u_Texture;

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

void main(){
    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = texColor + vec4( abs(sin(u_Time)), abs(sin(u_Time + 0.5f)), abs(sin(u_Time + 0.3f)),0.0f); 
}