#pragma once
#include "renderer/IRenderer.h"
#include "entity/Scene.h"

namespace MemoGL {
    class IGraphicsEngine {
        public:
            virtual void render(std::shared_ptr<Scene> scene, float lag) = 0;

            std::shared_ptr<IRenderer> getRenderer() {
                return renderer;
            }

        protected:
            std::shared_ptr<IRenderer> renderer = nullptr;
    };
}