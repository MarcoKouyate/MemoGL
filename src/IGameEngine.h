#pragma once
#include "graphics/IGraphicsEngine.h"

namespace MemoGL {
    class IGameEngine {
        public:
            virtual ~IGameEngine() = default;
            virtual void initialize(const GraphicsEngineType& graphicsType, const RendererType& rendererType, const WindowProperties& windowProperties) = 0;
            virtual void release() = 0;
            virtual void run() = 0;

            IGraphicsEngine* getGraphicsEngine(){
                return graphicsEngine;
            }

        protected:
            bool isInitialized = false;
            IGraphicsEngine* graphicsEngine;
    };
}