#pragma once
#include "graphics/renderer/IRenderer.h"
#include "versions/OpenGL3.h"
#include "versions/OpenGL4.h"
#include <string>

namespace MemoGL {
    class OpenGLRenderer : public IRenderer {
        public:
            void render() override;

            OpenGLRenderer();
            ~OpenGLRenderer();

        private:
            void init();
            void initializeWindow();
            void initializeGlew();
            void initializeShaders();
            void initializeUniforms(unsigned int shader);
            void initializeVertexBuffers();
            unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader);
            unsigned int compileShader(unsigned int type, const std::string& source);

            IOpenGLVersion* openGLVersion = nullptr;
    };
}