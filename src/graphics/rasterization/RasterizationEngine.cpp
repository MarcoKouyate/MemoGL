#include "RasterizationEngine.h"

#include <iostream>
#include <stdexcept>

namespace MemoGL {
    RasterizationEngine::RasterizationEngine(std::shared_ptr<IRenderer> pRenderer) {
        renderer = pRenderer;
        std::cout << "Rasterization graphics engine initialized." << std::endl;
        std::shared_ptr<Shader> shader = renderer->createShader("res/shaders/texture2d.vert", "res/shaders/texture2d.frag");
        std::shared_ptr<VertexArray> vertices = renderer->createVertexArray();
        std::shared_ptr<Object> entity = std::make_shared<Object>(shader, vertices);
        demo.addChild(entity);
    }

    RasterizationEngine::~RasterizationEngine() {
        std::cout << "Rasterization graphics engine has been released." << std::endl;
    }
        
    void RasterizationEngine::render(float lag) {
        renderer->begin();
        demo.render(*renderer);
        

        renderer->imGuiBegin();
        demo.imgui();
        renderer->imGuiEnd();
        renderer->end();

        
    }
}