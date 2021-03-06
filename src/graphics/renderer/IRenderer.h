#pragma once
#include "graphics/context/IWindow.h"
#include "tools/ColorStructs.h"

// buffers
#include "graphics/buffer/Shader.h"
#include "graphics/buffer/VertexArray.h"
#include "graphics/renderer/OpenGL/texture/OpenGLTexture.h"


namespace MemoGL {
    class IRenderer {
        public:
            virtual ~IRenderer() = default;

            virtual void clearColor(const RGBAColor& color) = 0;
            virtual void draw() = 0;

            virtual std::shared_ptr<Shader> createShader() = 0;
            virtual std::shared_ptr<VertexArray> createVertexArray() = 0;
            virtual std::shared_ptr<OpenGLTexture> createTexture() = 0;

            //TODO ImGui should be a separate renderer
            virtual void imGuiBegin() = 0;
            virtual void imGuiEnd() = 0;
    };
}