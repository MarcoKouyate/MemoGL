#pragma once
#include "graphics/renderer/IRenderer.h"
#include "versions/OpenGL3.h"
#include "versions/OpenGL4.h"
#include "buffer/OpenGLIndexBuffer.h"
#include "buffer/OpenGLVertexArray.h"
#include "texture/OpenGLTexture.h"
#include "shader/OpenGLShader.h"

#include <string>
#include <memory.h>

#include "imgui/OpenGLImGui.h"
#include "graphics/entity/demos/ClearColorDemo.h"

namespace MemoGL {
    class OpenGLRenderer : public IRenderer {
        public:
            void clearColor(const RGBAColor& color) override;

            void begin() override;
            void end() override;

            void imGuiBegin() override;
            void imGuiEnd() override;


            OpenGLRenderer();
            ~OpenGLRenderer();

        private:
            void init();
            void initializeWindow();
            std::unique_ptr<IOpenGLVersion> getOpenGLVersion();
            void initializeGlew();
            void initializeShaders();
            void initializeTextures();
            void initializeVertexBuffers();
            void initializeImGui();

            std::unique_ptr<IOpenGLVersion> openGLVersion = nullptr;
            std::unique_ptr<OpenGLVertexArray> vao = nullptr;
            std::shared_ptr<OpenGLVertexBuffer> vbo = nullptr;
            std::unique_ptr<OpenGLIndexBuffer> ibo = nullptr;
            std::unique_ptr<OpenGLTexture> texture = nullptr;
            std::unique_ptr<OpenGLShader> shader = nullptr;
            std::unique_ptr<OpenGLImGui> imgui = nullptr;

            glm::mat4 proj;
            glm::mat4 view;
            glm::mat4 model;
            glm::vec3 translationA;
            glm::vec3 translationB;

            float camera_position_x = 0;
            float camera_position_y = 0;
    };
}