#pragma once
#include "renderer/IRenderer.h"

namespace MemoGL {
    enum class GraphicsEngineType {
        Rasterization, 
        RayTracing
    };

    class IGraphicsEngine {
        public:
            virtual ~IGraphicsEngine() = default;
            virtual void initialize(const GraphicsEngineType& graphicsType, const RendererType& rendererType, const WindowProperties& windowProperties) = 0;
            virtual void release() = 0;
            virtual void render(float lag) = 0;

            IRenderer* getRenderer() {
                return renderer;
            }

        protected:
            bool isInitialized = false;
            IRenderer* renderer = nullptr;
    };
}