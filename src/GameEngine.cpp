#include "GameEngine.h"
#include "graphics/rasterization/RasterizationEngine.h"
#include <stdexcept>
#include <iostream>

namespace MemoGL {
    GameEngine::GameEngine(std::shared_ptr<IGraphicsEngine> pGraphicsEngine) {
        graphicsEngine = pGraphicsEngine;
        std::cout << "Game Engine initialized." << std::endl;
    }

    GameEngine::~GameEngine() {
        std::cout << "Game Engine has been deleted." << std::endl;
    }

    void GameEngine::run() {
        if (!graphicsEngine) {
            throw std::runtime_error("Game Engine tried to run without graphics engine.");
        }

        std::shared_ptr<IWindow> window = graphicsEngine->getRenderer()->getWindow();

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