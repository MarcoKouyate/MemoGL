#include "RasterizationEngine.h"

#include "tools/Log.h"
#include <stdexcept>

namespace MemoGL {

    IGraphicsEngine* RasterizationEngine::instance = nullptr;

    RasterizationEngine::RasterizationEngine() {
        renderer = std::make_shared<OpenGLRenderer>();
        MEMOGL_LOG_TRACE("Rasterization graphics engine initialized.");

        createScene();
    }

    RasterizationEngine::~RasterizationEngine() {
        MEMOGL_LOG_TRACE("Rasterization graphics engine has been released.");
    }

    void RasterizationEngine::createScene() {

        //demo->addChild(entity);
    }
        
    void RasterizationEngine::render(std::shared_ptr<Demo> scene,  float lag) {
        if (renderer) {
            renderer->begin();
            scene->render(*renderer);

            renderer->imGuiBegin();
            scene->imgui();
            renderer->imGuiEnd();
            renderer->end();
        }
    }
}