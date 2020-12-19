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
            void render(std::shared_ptr<Demo> scene, float lag) override;
            ~RasterizationEngine();

            static IGraphicsEngine* getInstance() {
                if (!instance) {
                    instance = new RasterizationEngine();
                }

                return instance;
            }

        private: 
            RasterizationEngine();
            void createScene();
            
            static IGraphicsEngine* instance;
    };
}