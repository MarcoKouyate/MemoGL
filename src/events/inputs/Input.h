#pragma once
#include "glm.hpp"

namespace MemoGL {
    class Input {
        public:
            virtual bool isKeyPressed(int keyCode) const = 0;
            virtual bool isMouseButtonPressed(int button) const = 0;
            virtual glm::vec2 getMousePosition() const = 0;

            float getMouseX() const { return getMousePosition().x;  }
            float getMouseY() const { return getMousePosition().y; }

            static Input* get();
            virtual ~Input() = default;

        protected:
          static Input* instance;
          Input() = default;
    };
}