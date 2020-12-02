#pragma once
#include "graphics/renderer/IRenderer.h"
#include "OpenGL33Window.h"
#include <string>

namespace MemoGL {
    class OpenGL33Renderer : public IRenderer {
        public:
            void render() override;
            OpenGL33Renderer(std::shared_ptr<IWindow> pWindow);
            ~OpenGL33Renderer();
        private:
            void init(std::shared_ptr<IWindow> pWindow);
            void initializeGlew();
            void initializeShaders();
            void initializeVertexBuffers();
            unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader);
            unsigned int compileShader(unsigned int type, const std::string& source);
            void clearGlErrors();
            bool logGlCalls(const char* functionName, const char* file, int line);
    };
}