#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace MemoGL {
    struct Version {
        unsigned int majorId;
        unsigned int minorId;
        
        Version(unsigned int majorId, unsigned int minorId) : majorId(majorId), minorId(minorId) {};
        Version() : Version(0, 0) {};
    };

    struct WindowSettings {
        unsigned int width;
        unsigned int height;
        const char* name;

        WindowSettings(unsigned int width, unsigned int height, const char* name) : width(width), height(height), name(name) {};
        WindowSettings() : width(), height(), name("") {};
    };

    enum class APIProfile { none, compatibility, core };

    struct ContextSettings {
        Version version;
        WindowSettings window;
        bool debugMode;
        APIProfile profile;
    };

    class IContext {
        public:
            virtual void init(ContextSettings* properties) = 0;
            virtual void swapBuffers() = 0;
            virtual void pollEvents() = 0;
            virtual double getTime() = 0;
            virtual bool isRunning() = 0;
            virtual void close() = 0;

            virtual GLFWwindow* get() {
                return window;
            }

        protected:
            GLFWwindow* window;
    };
}
