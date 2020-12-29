#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "events/Event.h"
#include <functional>


namespace MemoGL {
    struct Version {
        unsigned int majorId;
        unsigned int minorId;
        
        Version(unsigned int majorId = 0, unsigned int minorId = 0) : majorId(majorId), minorId(minorId) {};
    };

    struct WindowSettings {
        unsigned int width;
        unsigned int height;
        const char* name;

        WindowSettings(unsigned int width = 1200, unsigned int height = 720, const char* name = "MemoGL") : width(width), height(height), name(name) {};
    };

    enum class APIProfile { none = 0, compatibility, core };

    struct ContextSettings {
        Version version;
        WindowSettings window;
        bool debugMode = false;
        APIProfile profile = APIProfile::none;
    };

    class IContext {
        public:
            using EventCallBackFunction = std::function<void(Event&)>;

            virtual void init(const ContextSettings& properties) = 0;
            virtual double getTime() = 0;
            virtual bool isRunning() = 0;
            virtual void close() = 0;

            virtual ~IContext() = default;

            // loop 
            virtual void onUpdate() = 0;

            // getters
            virtual unsigned int getWidth() const = 0;
            virtual unsigned int getHeight() const = 0;
            virtual bool isVSync() const = 0;

            // setters
            virtual void setEventCallBack(const EventCallBackFunction& callback) = 0;
            virtual void setVSync(bool enabled) = 0;

            static IContext* create(const ContextSettings& properties); 
            //implement this method into a platform specific file and choose wich subclass to create

            GLFWwindow* getWindow() const {
                return window;
            }

            protected:
                GLFWwindow* window = nullptr;
    };
}
