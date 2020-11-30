#pragma once
#include "IWindow.h"

namespace MemoGL {

    enum RendererType {
        OpenGL33,
        OpenGL45,
        Vulkan
    };

    class IRenderer {
        public:
            virtual ~IRenderer() = default;
            virtual void initialize(const RendererType& rendererType, const WindowProperties& windowProperties) = 0;
            virtual void release() = 0;

            IWindow* getWindow(){
                return window;
            }

        protected:
            bool isInitialized; 
            IWindow* window = nullptr;
    };
}