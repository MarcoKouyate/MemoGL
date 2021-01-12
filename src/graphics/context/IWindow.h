#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "events/Event.h"



namespace MemoGL {

    struct WindowSettings {
        unsigned int width;
        unsigned int height;
        const char* name;

        WindowSettings(unsigned int width = 1200,
                       unsigned int height = 720,
                       const char* name = "MemoGL") : 
            width(width), height(height), name(name) 
        {};
    };

    class IWindow {
        public:
            using EventCallBackFunction = std::function<void(Event&)>;

            virtual ~IWindow() = default;

            virtual double getTime() = 0;
            virtual void close() = 0;

            // loop 
            virtual void onUpdate() = 0;

            // getters
            virtual unsigned int getWidth() const = 0;
            virtual unsigned int getHeight() const = 0;
            virtual bool isVSync() const = 0;

            // setters
            virtual void setEventCallBack(const EventCallBackFunction& callback) = 0;
            virtual void setVSync(bool enabled) = 0;

            static IWindow* create(const WindowSettings& properties); 
            //implement this method into a platform specific file and choose wich subclass to create

            virtual void* getNativeWindow() const = 0;
    };
}
