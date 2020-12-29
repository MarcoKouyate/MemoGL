#pragma once
#include "graphics/rasterization/RasterizationEngine.h"
#include <memory>

namespace MemoGL {
    class GameEngine {
        public:
            void run();
            void onEvent(Event& e);

            GameEngine();
            ~GameEngine();
        
        private:
            bool isRunning = true;

            std::unique_ptr<IContext> context;
            std::unique_ptr<IGraphicsEngine> graphicsEngine;
    };
}