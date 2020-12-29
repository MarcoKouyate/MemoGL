#pragma once
#include "graphics/IGraphicsEngine.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "entity/demos/BasicTextureDemo.h"
#include "entity/demos/MenuDemo.h"
//#include "graphics/entity/demos/ClearColorDemo.h"

namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            void render(std::shared_ptr<Demo> scene, float lag) override;
            
            RasterizationEngine(const IContext& context);
            virtual ~RasterizationEngine();

        private: 
            void createScene();
    };
}