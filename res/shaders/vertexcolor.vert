#version 330 core

layout(location = 0) in vec4 position;
layout(location = 2) in vec3 aColor;

 out vec3 vColor;

void main(){
    vColor = aColor;
    gl_Position = position; 
}