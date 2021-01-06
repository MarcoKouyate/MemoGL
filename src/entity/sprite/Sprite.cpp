#include "Sprite.h"
#include "imgui.h"

namespace MemoGL {
    Sprite::Sprite() : 
        Rectangle()
    {
        vertexShader = "res/shaders/texture2d.vert";
        fragmentShader = "res/shaders/texture2d.frag";
    }
}