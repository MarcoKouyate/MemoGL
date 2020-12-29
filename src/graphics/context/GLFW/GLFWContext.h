#pragma once
#include "../IContext.h"

namespace MemoGL {
    class GLFWContext : public IContext {
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

            GLFWContext(const WindowSettings& properties);
            ~GLFWContext() override;


        private:
            static bool GLFW_initialized;

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