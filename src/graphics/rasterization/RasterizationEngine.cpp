#include "RasterizationEngine.h"

#include <iostream>
#include <stdexcept>

namespace MemoGL {
    RasterizationEngine::RasterizationEngine(std::shared_ptr<IRenderer> pRenderer) {
        renderer = pRenderer;
        std::cout << "Rasterization graphics engine initialized." << std::endl;
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