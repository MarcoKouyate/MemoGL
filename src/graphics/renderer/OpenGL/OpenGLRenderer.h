#pragma once
#include "graphics/renderer/IRenderer.h"
#include "versions/OpenGL3.h"
#include "versions/OpenGL4.h"
#include "buffer/OpenGLIndexBuffer.h"
#include "buffer/OpenGLVertexArray.h"
#include "texture/OpenGLTexture.h"
#include "shader/OpenGLShader.h"

#include "pch.h"

#include "imgui/OpenGLImGui.h"

#include "entity/Object.h"

namespace MemoGL {
    class OpenGLRenderer : public IRenderer {
        public:
            void clearColor(const RGBAColor& color) override;
            void draw();

            std::shared_ptr<Shader> createShader() override;
            std::shared_ptr<VertexArray> createVertexArray() override;

            void imGuiBegin() override;
            void imGuiEnd() override;


            OpenGLRenderer(const IContext& context);
            ~OpenGLRenderer();

        private:
            void init();
            void initializeWindow();
            void initializeGlew();
            void initializeTextures();
            void initializeImGui();
            
            
            const IContext& context;
            std::unique_ptr<IOpenGLVersion> openGLVersion = nullptr;
            std::unique_ptr<OpenGLTexture> texture = nullptr;
            std::unique_ptr<OpenGLImGui> imgui = nullptr;


    };
}