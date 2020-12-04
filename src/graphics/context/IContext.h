#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace MemoGL {
    struct Version {
        unsigned int major;
        unsigned int minor;
        
        Version(unsigned int major, unsigned int minor) : major(major), minor(minor) {};
        Version() : Version(0, 0) {};
    };

    struct WindowSettings {
        unsigned int width;
        unsigned int height;
        const char* name;

        WindowSettings(unsigned int width, unsigned int height, const char* name) : width(width), height(height), name(name) {};
        WindowSettings() : width(), height(), name("") {};
    };

    struct ContextSettings {
        Version version;
        WindowSettings window;
        bool debugMode;
    };

    class IContext {
        public:
            virtual void init(const ContextSettings& properties) = 0;
            virtual void swapBuffers() = 0;
            virtual bool isRunning() = 0;
            virtual void close() = 0;

            virtual GLFWwindow* get() {
                return window;
            }

        protected:
            GLFWwindow* window;
    };
}
