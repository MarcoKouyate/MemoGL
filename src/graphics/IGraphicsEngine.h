#pragma once
#include "renderer/IRenderer.h"

namespace MemoGL {
    class IGraphicsEngine {
        public:
            virtual void render(float lag) = 0;

            std::shared_ptr<IRenderer> getRenderer() {
                return renderer;
            }

        protected:
            std::shared_ptr<IRenderer> renderer = nullptr;
    };
}