#pragma once
#include "graphics/IGraphicsEngine.h"
#include "entity/EntityStack.h"


namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            void render(const EntityStack& entityStack) override;
            
            RasterizationEngine(const IWindow& context);
            virtual ~RasterizationEngine();
    };
}