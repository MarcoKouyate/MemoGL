#pragma once
#include "renderer/IRenderer.h"
#include "entity/EntityStack.h"

namespace MemoGL {
    class IGraphicsEngine {
        public:
            virtual void render(const EntityStack& entityStack) = 0;

            std::shared_ptr<IRenderer> getRenderer() {
                return renderer;
            }

        protected:
            std::shared_ptr<IRenderer> renderer = nullptr;
    };
}