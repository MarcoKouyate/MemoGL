#pragma once
#include "graphics/IGraphicsEngine.h"
#include <memory>

namespace MemoGL {
    class IGameEngine {
        public:
            virtual void run() = 0;

            std::shared_ptr<IGraphicsEngine> getGraphicsEngine(){
                return graphicsEngine;
            }

        protected:
            std::shared_ptr<IGraphicsEngine> graphicsEngine;
    };
}