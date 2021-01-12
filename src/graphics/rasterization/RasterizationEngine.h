#pragma once
#include "graphics/IGraphicsEngine.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"

//#include "graphics/entity/demos/ClearColorDemo.h"

namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            void render(std::shared_ptr<Scene> scene, float lag) override;
            
            RasterizationEngine(const IWindow& context);
            virtual ~RasterizationEngine();
    };
}