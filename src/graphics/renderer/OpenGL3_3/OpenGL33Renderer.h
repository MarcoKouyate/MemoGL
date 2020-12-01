#pragma once
#include "graphics/renderer/IRenderer.h"
#include "OpenGL33Window.h"

namespace MemoGL {
    class OpenGL33Renderer : public IRenderer {
        public:
            void render() override;
            OpenGL33Renderer(std::shared_ptr<IWindow> pWindow);
            ~OpenGL33Renderer();
        private:
            void init(std::shared_ptr<IWindow> pWindow);
            void initializeGlew();
    };
}