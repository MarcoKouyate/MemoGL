#pragma once
#include "glm.hpp"

namespace MemoGL {
    struct Vertex2D {
        glm::vec2 position;
        glm::vec2 textureCoordinates;
        glm::vec3 color;


        Vertex2D() : 
            position(0.0, 0.0), textureCoordinates(0.0, 0.0), color(1.0, 1.0, 1.0)
        {}

        Vertex2D(glm::vec2 position, glm::vec2 textureCoordinates, glm::vec3 color) :
            position(position), textureCoordinates(textureCoordinates), color(color)
        {}
    };
}