#pragma once
#include "../IWindow.h"

namespace MemoGL {
    class WindowGLFW : public IWindow {
        public:
            void init(const WindowSettings& properties);

            double getTime() override;
            void close() override;

            virtual void onUpdate() override;

            virtual unsigned int getWidth() const override;
            virtual unsigned int getHeight() const override;
            virtual bool isVSync() const override;

            virtual void setEventCallBack(const EventCallBackFunction & callback) override;
            virtual void setVSync(bool enabled) override;

            WindowGLFW(const WindowSettings& properties);
            ~WindowGLFW() override;

            void* getNativeWindow() const override {
                return window;
            }

        private:
            static bool GLFW_initialized;
            GLFWwindow* window = nullptr;

            struct  WindowData
            {
                std::string title;
                unsigned int width, height;
                bool vSync;

                EventCallBackFunction eventCallback;
            };

            WindowData windowData;
    };
}