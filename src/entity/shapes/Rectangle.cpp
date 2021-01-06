#include "Rectangle.h"

namespace MemoGL {
    Rectangle::Rectangle() {
        vertices = {
            Vertex2D(glm::vec2(-0.5, -0.5), glm::vec2(0, 0), glm::vec3(1, 0, 0)),
            Vertex2D(glm::vec2(0.5, -0.5), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
            Vertex2D(glm::vec2(0.5, 0.5), glm::vec2(1, 1), glm::vec3(0, 0, 1)),
            Vertex2D(glm::vec2(-0.5, 0.5), glm::vec2(0, 1), glm::vec3(1, 1, 1))
        };

        indices = {
            0, 1, 2,
            2, 3, 0
        };
    }
}