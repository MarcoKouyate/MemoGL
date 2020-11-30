#include "RasterizationEngine.h"
#include "graphics/renderer/OpenGL3_3/OpenGL33Renderer.h"
#include <iostream>
#include <stdexcept>

namespace MemoGL {
    RasterizationEngine::~RasterizationEngine() {
        release();
    }

    void RasterizationEngine::initialize(const GraphicsEngineType& graphicsType, const RendererType& rendererType, const WindowProperties& windowProperties) {
        if (isInitialized) {
            release();
        }

        std::cout << "Initializing Rasterization graphics engine..." << std::endl;

        switch(graphicsType) {
            case GraphicsEngineType::Rasterization: 
                renderer = new OpenGL33Renderer();
                break;
            
            case GraphicsEngineType::RayTracing:
                std::runtime_error("Raytracing graphics engine hasn't been implemented yet!");
                break;
        }

        if(!renderer) {
            std::bad_alloc();
        }

        isInitialized = true;

        renderer->initialize(rendererType, windowProperties);

        std::cout << "Rasterization graphics engine initialized." << std::endl;
    }

    void RasterizationEngine::release() {
        if (isInitialized) {
            isInitialized = false;

            if(renderer) {
                renderer->release();
                delete renderer;
                renderer = nullptr;
            }

            std::cout << "Rasterization graphics engine has been released." << std::endl;
        }
    }
        
    void RasterizationEngine::render(float lag) {

        glfwSwapBuffers(renderer->getWindow()->get());
    }
}