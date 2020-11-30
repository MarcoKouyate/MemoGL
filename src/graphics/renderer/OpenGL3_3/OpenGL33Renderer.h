#pragma once
#include "graphics/renderer/IRenderer.h"
#include "OpenGL33Window.h"

namespace MemoGL {
    class OpenGL33Renderer : public IRenderer {
        public:
            ~OpenGL33Renderer() override;
            void initialize(const RendererType& rendererType, const WindowProperties& windowProperties) override;
            void release() override;

        private:
            OpenGL33Window m_window;
    };
}