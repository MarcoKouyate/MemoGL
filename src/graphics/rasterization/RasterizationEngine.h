#pragma once
#include "graphics/IGraphicsEngine.h"

namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            ~RasterizationEngine() override;
            void initialize(const GraphicsEngineType& graphicsType, const RendererType& rendererType, const WindowProperties& windowProperties) override;
            void release() override;
            void render(float lag) override;
    };
}