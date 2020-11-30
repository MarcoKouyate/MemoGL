#pragma once
#include "IWindow.h"
#include <memory>

namespace MemoGL {

    enum RendererType {
        OpenGL33,
        OpenGL45,
        Vulkan
    };

    class IRenderer {
        public:
            virtual ~IRenderer() = default;
            virtual void initialize(std::shared_ptr<IWindow> pWindow) = 0;
            virtual void release() = 0;

            std::shared_ptr<IWindow> getWindow(){
                return window;
            }

        protected:
            bool isInitialized; 
            std::shared_ptr<IWindow> window = nullptr;
    };
}