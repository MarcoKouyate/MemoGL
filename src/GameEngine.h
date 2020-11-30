#pragma once
#include "IGameEngine.h"

namespace MemoGL {
    class GameEngine : public IGameEngine {
        public:
            ~GameEngine() override;
            void initialize(const GraphicsEngineType& graphicsType, const RendererType& rendererType, const WindowProperties& windowProperties) override;
            void release() override;
            void run() override;

    };
}