#pragma once
#include "graphics/IGraphicsEngine.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "entity/EntityStack.h"

//#include "graphics/entity/demos/ClearColorDemo.h"

namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            void render(const EntityStack& entityStack) override;
            
            RasterizationEngine(const IWindow& context);
            virtual ~RasterizationEngine();
    };
}