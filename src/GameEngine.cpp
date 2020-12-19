#include "GameEngine.h"
#include "graphics/rasterization/RasterizationEngine.h"
#include "graphics/entity/SceneManager.h"
#include <stdexcept>
#include <iostream>

namespace MemoGL {
    GameEngine::GameEngine() {
        std::cout << "Game Engine initialized." << std::endl;
        graphicsEngine = RasterizationEngine::getInstance();
    }

    GameEngine::~GameEngine() {
        std::cout << "Game Engine has been deleted." << std::endl;
    }

    void GameEngine::run() {
        if (!graphicsEngine) {
            throw std::runtime_error("Game Engine tried to run without graphics engine.");
        }

        std::shared_ptr<IContext> context = graphicsEngine->getRenderer()->getContext();

        SceneManager* sceneManager = SceneManager::getInstance();
        sceneManager->load(std::make_shared<MenuDemo>());

        double lag = 0.0;
        double previous = context->getTime();
        double SECONDS_PER_UPDATE = 1.0 / 60.0;

        while (context->isRunning()) {

            double current = context->getTime();
            double elapsed = current - previous;
            previous = current;

            lag += elapsed;

            // input update
            context->pollEvents();

            while (lag >= SECONDS_PER_UPDATE) {
                // Game logic
                lag -= SECONDS_PER_UPDATE;
            }

            // Rendering
            graphicsEngine->render(sceneManager->getCurrentScene(),(float)lag / SECONDS_PER_UPDATE);
        }
    }
}