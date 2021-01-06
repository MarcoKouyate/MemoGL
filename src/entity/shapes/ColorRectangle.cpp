#include "ColorRectangle.h"
#include "imgui.h"

namespace MemoGL {
    ColorRectangle::ColorRectangle() :
        Rectangle()
    {
        vertexShader = "res/shaders/basic.vert";
        fragmentShader = "res/shaders/plaincolor.frag";
    }
}