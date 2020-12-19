#pragma once
#include "graphics/rasterization/RasterizationEngine.h"

namespace MemoGL {
    class GameEngine {
        public:
            void run();

            GameEngine();
            ~GameEngine();
        
        private:
            IGraphicsEngine* graphicsEngine;

    };
}