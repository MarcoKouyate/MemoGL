#pragma once
#include "graphics/renderer/IRenderer.h"

// imgui
#include "imgui/OpenGLImGui.h"
#include "versions/IOpenGLVersion.h"


//entities
#include "entity/Object.h"

namespace MemoGL {
    class OpenGLRenderer : public IRenderer {
        public:
            void clearColor(const RGBAColor& color) override;
            void draw() override;

            std::shared_ptr<Shader> createShader() override;
            std::shared_ptr<VertexArray> createVertexArray() override;
            std::shared_ptr<OpenGLTexture> createTexture() override;

            void imGuiBegin() override;
            void imGuiEnd() override;


            OpenGLRenderer(const IWindow& context);
            ~OpenGLRenderer();

        private:
            void init();
            void initializeWindow();
            void initializeGlew();
            void initializeTextures();
            void initializeImGui();
            
            
            const IWindow& context;
            std::unique_ptr<IOpenGLVersion> openGLVersion = nullptr;
            std::unique_ptr<OpenGLImGui> imgui = nullptr;
    };
}
