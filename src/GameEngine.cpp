#include "GameEngine.h"
#include "graphics/rasterization/RasterizationEngine.h"
#include "entity/SceneManager.h"
#include "tools/Log.h"
#include "entity/sprite/Sprite.h"
#include "entity/shapes/ColorRectangle.h"
#include "entity/demos/MenuDemo.h"
#include "events/inputs/Input.h"

namespace MemoGL {
    #define EVENT_CALLBACK(x) std::bind(&x, this, std::placeholders::_1)

    GameEngine* GameEngine::instance = nullptr;

    GameEngine* GameEngine::get() {
        if (!instance) {
            instance = new GameEngine;
        }
        return instance;
    }

    GameEngine::GameEngine() {
        MEMOGL_LOG_TRACE("Game Engine initialized.")
        context = std::unique_ptr<IWindow>(IWindow::create(WindowSettings()));
        context->setEventCallBack(EVENT_CALLBACK(GameEngine::onEvent));
        graphicsEngine = std::make_shared<RasterizationEngine>(*context);
    }

    GameEngine::~GameEngine() {
        MEMOGL_LOG_TRACE("Game Engine has been deleted.");
    }

    void GameEngine::run() {
        if (!graphicsEngine) {
            throw std::runtime_error("Game Engine tried to run without graphics engine.");
        }

        SceneManager::getInstance()->load(std::make_shared<MenuDemo>());

        lag = 0.0;
        previous = context->getTime();

        while (isRunning) {
            checkActiveScene();
            update();
            render();
        }
    }



    // Frame Loop

    void GameEngine::checkActiveScene() {
        if (SceneManager::getInstance()->getCurrentScene() != loadedScene) {
            std::shared_ptr<Scene> currentScene = SceneManager::getInstance()->getCurrentScene();
            loadScene(currentScene);
            loadedScene = currentScene;
        }
    }

    void GameEngine::update() {
        context->onUpdate();

        double current = context->getTime();
        double elapsed = current - previous;
        previous = current;

        lag += elapsed;

        while (lag >= SECONDS_PER_UPDATE) {
            // Game logic
            for (auto& entity : entityStack) {
                entity->update((float)lag);
            }
            lag -= SECONDS_PER_UPDATE;
        }
    }

    void GameEngine::render() {
        graphicsEngine->render(entityStack);
    }




    // Load

    void GameEngine::loadScene(std::shared_ptr<Scene> scene) {
        entityStack.clear();
        loadEntity(scene);
    }

    void GameEngine::loadEntity(std::shared_ptr<Entity> entity) {
        entityStack.pushLayer(entity);
        for (auto& child : entity->getChildren()) {
            loadEntity(child);
        }
    }



    // Events

    void GameEngine::onEvent(Event& e) {
        EventDispatcher dispatcher(e);
        propagateEventToLayers(e);
        dispatcher.dispatch<WindowCloseEvent>(EVENT_CALLBACK(GameEngine::onWindowClosed));
    }

    void GameEngine::propagateEventToLayers(Event& e) {
        for (auto it = entityStack.rbegin(); it != entityStack.rend(); ++it) {
            (*it)->onEvent(e);
            if (e.handled) {
                break;
            }
        }
    }


    bool GameEngine::onWindowClosed(WindowCloseEvent& e) {
        isRunning = false;
        return true;
    }
}