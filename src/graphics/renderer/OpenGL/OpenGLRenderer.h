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
            void render() override;

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
            void drawImGui();

            std::unique_ptr<IOpenGLVersion> openGLVersion = nullptr;
            std::unique_ptr<OpenGLVertexArray> vao = nullptr;
            std::shared_ptr<OpenGLVertexBuffer> vbo = nullptr;
            std::unique_ptr<OpenGLIndexBuffer> ibo = nullptr;
            std::unique_ptr<OpenGLTexture> texture = nullptr;
            std::unique_ptr<OpenGLShader> shader = nullptr;
            std::unique_ptr<OpenGLImGui> imgui = nullptr;
            std::unique_ptr<ClearColorDemo> demo = nullptr;

            glm::mat4 proj;
            glm::mat4 view;
            glm::mat4 model;
            glm::vec3 translationA;
            glm::vec3 translationB;

            bool show_demo_window = true;
            ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
            float camera_position_x = 0;
            float camera_position_y = 0;
    };
}