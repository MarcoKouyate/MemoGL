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

#include "entity/Object.h"

namespace MemoGL {
    class OpenGLRenderer : public IRenderer {
        public:
            void clearColor(const RGBAColor& color) override;
            void draw();

            std::shared_ptr<Shader> createShader(const std::string& vertex, const std::string& fragment) override;
            std::shared_ptr<VertexArray> createVertexArray() override;

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
            void initializeTextures();
            void initializeImGui();

            std::unique_ptr<IOpenGLVersion> openGLVersion = nullptr;
            std::shared_ptr<OpenGLVertexBuffer> vbo = nullptr;
            std::unique_ptr<OpenGLIndexBuffer> ibo = nullptr;
            std::unique_ptr<OpenGLTexture> texture = nullptr;
            std::unique_ptr<OpenGLImGui> imgui = nullptr;


    };
}