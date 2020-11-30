#pragma once
#include "graphics/renderer/IRenderer.h"
#include "OpenGL33Window.h"

namespace MemoGL {
    class OpenGL33Renderer : public IRenderer {
        public:
            OpenGL33Renderer(std::shared_ptr<IWindow> pWindow);
            ~OpenGL33Renderer();
    };
}