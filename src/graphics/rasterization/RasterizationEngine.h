#pragma once
#include "graphics/IGraphicsEngine.h"
#include "graphics/renderer/OpenGL3_3/OpenGL33Renderer.h"
#include "graphics/renderer/OpenGL_Legacy/OpenGLLegacyRenderer.h"
#include "graphics/renderer/OpenGL4/OpenGL4Renderer.h"

namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            void render(float lag) override;

            RasterizationEngine(std::shared_ptr<IRenderer> pRenderer);
            ~RasterizationEngine();
    };
}