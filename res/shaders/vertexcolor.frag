#version 330 core

layout(location = 0) out vec4 color;
uniform vec4 u_Color;
uniform sampler2D u_Texture_Slot;

in vec2 v_texCoord;
in vec3 vColor;

void main(){
    vec4 texColor = texture(u_Texture_Slot, v_texCoord);
    //color = texColor;
    color = vec4(vColor.rgb, 1.0f);
}