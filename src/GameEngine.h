#pragma once
#include "IGameEngine.h"
#include "graphics/rasterization/RasterizationEngine.h"

namespace MemoGL {
    class GameEngine : public IGameEngine {
        public:
            ~GameEngine() override;
            void initialize(std::shared_ptr<IGraphicsEngine> pGraphicsEngine) override;
            void release() override;
            void run() override;

    };
}