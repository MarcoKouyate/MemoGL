#pragma once
#include "graphics/context/IContext.h"
#include "tools/ColorStructs.h"
#include "graphics/entity/Shader.h"
#include "graphics/entity/VertexArray.h"

#include <memory>

namespace MemoGL {
    class IRenderer {
        public:
            virtual ~IRenderer() = default;

            virtual void clearColor(const RGBAColor& color) = 0;
            virtual void draw() = 0;
            virtual void begin() = 0;
            virtual void end() = 0;

            virtual std::shared_ptr<Shader> createShader(const std::string& vertex, const std::string& fragment) = 0;
            virtual std::shared_ptr<VertexArray> createVertexArray() = 0;

            //TODO ImGui should be a separate renderer
            virtual void imGuiBegin() = 0;
            virtual void imGuiEnd() = 0;

            std::shared_ptr<IContext> getContext() {
                return context;
            }

        protected:
            std::shared_ptr<IContext> context = nullptr;
    };
}