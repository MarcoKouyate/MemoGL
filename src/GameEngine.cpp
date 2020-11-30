#include "GameEngine.h"
#include "graphics/rasterization/RasterizationEngine.h"
#include <stdexcept>
#include <iostream>

namespace MemoGL {
    GameEngine::~GameEngine(){
        release();
    }

    void GameEngine::initialize(const GraphicsEngineType& graphicsType, const RendererType& rendererType, const WindowProperties& windowProperties) {
        if (isInitialized) {
            release();
        }

        std::cout << "Initializing Game Engine..." << std::endl;
        
        switch(graphicsType) {
            case GraphicsEngineType::Rasterization: 
                graphicsEngine = new RasterizationEngine();
                break;
            case GraphicsEngineType::RayTracing:
                throw std::runtime_error("Raytracing engine not implemented yet.");
                break;
        }

        if(!graphicsEngine) {
            throw std::bad_alloc();
        }

        isInitialized = true;
        graphicsEngine->initialize(graphicsType, rendererType, windowProperties);

        std::cout << "Game Engine initialized." << std::endl;
    }

    void GameEngine::release() {
        if (isInitialized) {

            if(graphicsEngine) {
                graphicsEngine->release();
                delete graphicsEngine;
                graphicsEngine = nullptr;
            }

            isInitialized = false;
            std::cout << "Game Engine has been released." << std::endl;
        }

    }

    void GameEngine::run() {
        if (!isInitialized) {
            throw std::runtime_error("Game Engine tried to run without being initialized.");
        }

        IWindow* window = graphicsEngine->getRenderer()->getWindow();

        double lag = 0.0;
        double previous = glfwGetTime();
        double SECONDS_PER_UPDATE = 1.0 / 60.0;

        while (window->isRunning()) {

            double current = glfwGetTime();
            double elapsed = current - previous;
            previous = current;

            lag += elapsed;

            // input update
            glfwPollEvents();

            while (lag >= SECONDS_PER_UPDATE) {
                // Game logic
                lag -= SECONDS_PER_UPDATE;
            }

            // Rendering
            graphicsEngine->render((float)lag / SECONDS_PER_UPDATE);
        }
    }
}