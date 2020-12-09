#pragma once
#include "graphics/renderer/IRenderer.h"
#include "versions/OpenGL3.h"
#include "versions/OpenGL4.h"
#include <string>
#include <memory.h>
#include "buffer/OpenGLIndexBuffer.h"
#include "buffer/OpenGLVertexArray.h"

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
            void initializeVertexBuffers();

            std::unique_ptr<IOpenGLVersion> openGLVersion = nullptr;
            std::unique_ptr<OpenGLVertexArray> vao = nullptr;
            std::shared_ptr<OpenGLVertexBuffer> vbo = nullptr;
            std::unique_ptr<OpenGLIndexBuffer> ibo = nullptr;
    };
}