#pragma once
#include "graphics/renderer/IRenderer.h"
#include "versions/OpenGL3.h"
#include "versions/OpenGL4.h"
#include <string>
#include <memory.h>
#include "buffer/OpenGLIndexBuffer.h"
#include "buffer/OpenGLVertexBuffer.h"

namespace MemoGL {
    class OpenGLRenderer : public IRenderer {
        public:
            void render() override;

            OpenGLRenderer();
            ~OpenGLRenderer();

        private:
            void init();
            void initializeWindow();
            std::unique_ptr<IOpenGLVersion> getOpenGLVersion();
            void initializeGlew();
            void initializeShaders();
            void initializeUniforms(unsigned int shader);
            void initializeVertexBuffers();
            unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader);
            unsigned int compileShader(unsigned int type, const std::string& source);

            std::unique_ptr<IOpenGLVersion> openGLVersion = nullptr;
            std::unique_ptr<OpenGLVertexBuffer> vbo = nullptr;
            std::unique_ptr<OpenGLIndexBuffer> ibo = nullptr;
    };
}