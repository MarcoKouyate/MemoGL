#pragma once
#include "IGameEngine.h"
#include "graphics/rasterization/RasterizationEngine.h"

namespace MemoGL {
    class GameEngine : public IGameEngine {
        public:
            void run() override;

            GameEngine();
            ~GameEngine();
        
        private:
            IGraphicsEngine* graphicsEngine;

    };
}