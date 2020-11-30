#include "RasterizationEngine.h"

#include <iostream>
#include <stdexcept>

namespace MemoGL {
    RasterizationEngine::~RasterizationEngine() {
        release();
    }

    void RasterizationEngine::initialize(std::shared_ptr<IRenderer> pRenderer) {
        if (isInitialized) {
            release();
        }

        std::cout << "Initializing Rasterization graphics engine..." << std::endl;

        renderer = pRenderer;

        if(!renderer) {
            std::bad_alloc();
        }

        isInitialized = true;

        std::cout << "Rasterization graphics engine initialized." << std::endl;
    }

    void RasterizationEngine::release() {
        if (isInitialized) {

            if(renderer) {
                renderer = nullptr;
            }

            isInitialized = false;
            std::cout << "Rasterization graphics engine has been released." << std::endl;
        }
    }
        
    void RasterizationEngine::render(float lag) {

        glfwSwapBuffers(renderer->getWindow()->get());
    }
}