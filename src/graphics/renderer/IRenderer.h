#pragma once
#include "graphics/context/IContext.h"
#include "tools/ColorStructs.h"
#include <memory>

namespace MemoGL {
    class IRenderer {
        public:
            virtual void clearColor(const RGBAColor& color) = 0;
            virtual void begin() = 0;
            virtual void end() = 0;


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