#pragma once
#include "Input.h"

namespace MemoGL {
    class GLFWInput : public Input {
        public:
            bool isKeyPressed(int keyCode) const override;
            bool isMouseButtonPressed(int button) const override;

            glm::vec2 getMousePosition() const override;

            GLFWInput() {}
    };
}