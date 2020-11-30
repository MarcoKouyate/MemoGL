#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace MemoGL {
    struct WindowProperties {
        unsigned int width;
        unsigned int height;
        const char* name;
    };

    class IWindow {
        public:
            virtual bool isRunning() = 0;
            virtual void close() = 0;

            virtual GLFWwindow* get() {
                return window;
            }

        protected:
            GLFWwindow* window;
    };
}
