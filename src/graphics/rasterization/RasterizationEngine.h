#pragma once
#include "graphics/IGraphicsEngine.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "graphics/entity/demos/BasicTextureDemo.h"
#include "graphics/entity/demos/MenuDemo.h"
//#include "graphics/entity/demos/ClearColorDemo.h"

namespace MemoGL {
    class RasterizationEngine : public IGraphicsEngine{
        public:
            void render(float lag) override;
            

            RasterizationEngine(std::shared_ptr<IRenderer> pRenderer);
            ~RasterizationEngine();

        private: 
            void createScene();
            std::shared_ptr<Demo> demo = nullptr;
    };
}