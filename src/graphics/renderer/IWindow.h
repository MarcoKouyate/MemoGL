#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace MemoGL {
    class IWindow {
        public:
            virtual ~IWindow() = default;
            virtual void initialize(int width, int height, const char* name) = 0;
            virtual void release() = 0;

            virtual GLFWwindow* get() {
                return window;
            }

        protected:
            GLFWwindow* window;
    };
}
