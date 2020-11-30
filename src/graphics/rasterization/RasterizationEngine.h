#pragma once
#include "graphics/IGraphicsEngine.h"
#include "graphics/renderer/OpenGL3_3/OpenGL33Renderer.h"

namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            ~RasterizationEngine() override;
            void initialize(std::shared_ptr<IRenderer> pRenderer) override;
            void release() override;
            void render(float lag) override;
    };
}