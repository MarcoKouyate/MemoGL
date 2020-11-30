#pragma once
#include "graphics/IGraphicsEngine.h"
#include <memory>

namespace MemoGL {
    class IGameEngine {
        public:
            virtual ~IGameEngine() = default;
            virtual void initialize(std::shared_ptr<IGraphicsEngine> pGraphicsEngine) = 0;
            virtual void release() = 0;
            virtual void run() = 0;

            std::shared_ptr<IGraphicsEngine> getGraphicsEngine(){
                return graphicsEngine;
            }

        protected:
            bool isInitialized = false;
            std::shared_ptr<IGraphicsEngine> graphicsEngine;
    };
}