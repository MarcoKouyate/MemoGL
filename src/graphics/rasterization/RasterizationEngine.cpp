#include "RasterizationEngine.h"

#include <iostream>
#include <stdexcept>

namespace MemoGL {

    IGraphicsEngine* RasterizationEngine::instance = nullptr;

    RasterizationEngine::RasterizationEngine() {
        renderer = std::make_shared<OpenGLRenderer>();
        std::cout << "Rasterization graphics engine initialized." << std::endl;

        createScene();
    }

    RasterizationEngine::~RasterizationEngine() {
        std::cout << "Rasterization graphics engine has been released." << std::endl;
    }

    void RasterizationEngine::createScene() {
        //std::shared_ptr<Shader> shader = renderer->createShader("res/shaders/texture2d.vert", "res/shaders/texture2d.frag");
        //std::shared_ptr<VertexArray> vertices = renderer->createVertexArray();
        //std::shared_ptr<Object> entity = std::make_shared<Object>(shader, vertices);
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