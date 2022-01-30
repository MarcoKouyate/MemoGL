#include "RasterizationEngine.h"

#include "tools/Log.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"


namespace MemoGL {
    RasterizationEngine::RasterizationEngine(const IWindow& context) {
        renderer = std::make_shared<OpenGLRenderer>(context);
        MEMOGL_LOG_TRACE("Rasterization graphics engine initialized.");
    }

    RasterizationEngine::~RasterizationEngine() {
        MEMOGL_LOG_TRACE("Rasterization graphics engine has been released.");
    }
        
    void RasterizationEngine::render(const EntityStack& entityStack) {
        if (renderer) {
            renderer->clearColor({ 0.0f, 0.0f, 0.0f, 1.0f });

            for (auto& entity : entityStack) {
                entity->updateMVP();
                entity->render();
            }

            renderer->imGuiBegin();
            
            for (auto& entity : entityStack) {
                entity->imgui();
            }

            renderer->imGuiEnd();
        }
    }
}