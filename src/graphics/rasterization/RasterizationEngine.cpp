#include "RasterizationEngine.h"

#include "tools/Log.h"
#include <stdexcept>

namespace MemoGL {
    RasterizationEngine::RasterizationEngine(const IContext& context) {
        renderer = std::make_shared<OpenGLRenderer>(context);
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
            scene->render(*renderer);

            renderer->imGuiBegin();
            scene->imgui();
            renderer->imGuiEnd();
        }
    }
}