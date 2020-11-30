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
            virtual void initialize(std::shared_ptr<IRenderer> pRenderer) = 0;
            virtual void release() = 0;
            virtual void render(float lag) = 0;

            std::shared_ptr<IRenderer> getRenderer() {
                return renderer;
            }

        protected:
            bool isInitialized = false;
            std::shared_ptr<IRenderer> renderer = nullptr;
    };
}