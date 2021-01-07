#include "RasterizationEngine.h"

#include "tools/Log.h"


namespace MemoGL {
    RasterizationEngine::RasterizationEngine(const IContext& context) {
        renderer = std::make_shared<OpenGLRenderer>(context);
        MEMOGL_LOG_TRACE("Rasterization graphics engine initialized.");
    }

    RasterizationEngine::~RasterizationEngine() {
        MEMOGL_LOG_TRACE("Rasterization graphics engine has been released.");
    }
        
    void RasterizationEngine::render(std::shared_ptr<Scene> scene,  float lag) {
        if (renderer) {
            renderer->clearColor({ 0.0f, 0.0f, 0.0f, 1.0f });
            scene->render(*renderer);

            renderer->imGuiBegin();
            scene->imgui();
            renderer->imGuiEnd();
        }
    }
}