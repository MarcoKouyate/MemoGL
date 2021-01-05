#pragma once

#include "graphics/rasterization/RasterizationEngine.h"
#include "events/WindowEvents.h"
#include "layers/LayerStack.h"

namespace MemoGL {
    class GameEngine {
        public:
            void run();
            void onEvent(Event& e);

            void pushLayer(Layer* layer);
            void pushOverlay(Layer* overlay);

            GameEngine();
            ~GameEngine();
        
        private:
            bool onWindowClosed(WindowCloseEvent& e);
            void propagateEventToLayers(Event& e);

            LayerStack layerStack;

            bool isRunning = true;
            std::unique_ptr<IContext> context;
            std::unique_ptr<IGraphicsEngine> graphicsEngine;
    };
}