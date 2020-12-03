#pragma once
#include "graphics/renderer/IRenderer.h"
#include "OpenGL4Window.h"
#include <string>

namespace MemoGL {
    class OpenGL4Renderer : public IRenderer {
        public:
            void render() override;
            OpenGL4Renderer(std::shared_ptr<IWindow> pWindow);
            ~OpenGL4Renderer();
        private:
            void init(std::shared_ptr<IWindow> pWindow);
            void initializeGlew();
            void initializeShaders();
            void initializeVertexBuffers();
            unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader);
            unsigned int compileShader(unsigned int type, const std::string& source);
    };
}