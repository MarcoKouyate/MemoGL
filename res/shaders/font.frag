#version 330 core

layout(location = 0) out vec4 color;
uniform vec4 u_Color;
uniform sampler2D u_Texture_Slot;

in vec2 v_texCoord;

void main(){
    float alpha = texture(u_Texture_Slot, v_texCoord).r;
    vec4 fontColor = vec4(1, 1, 1, alpha);
    color = fontColor;
}