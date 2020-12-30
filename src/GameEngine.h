#pragma once
#include "pch.h"

#include "graphics/rasterization/RasterizationEngine.h"
#include "events/WindowEvents.h"

namespace MemoGL {
    class GameEngine {
        public:
            void run();
            void onEvent(Event& e);

            

            GameEngine();
            ~GameEngine();
        
        private:
            bool onWindowClosed(WindowCloseEvent& e);

            bool isRunning = true;

            std::unique_ptr<IContext> context;
            std::unique_ptr<IGraphicsEngine> graphicsEngine;
    };
}