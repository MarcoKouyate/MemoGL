#include "GameEngine.h"
#include "graphics/rasterization/RasterizationEngine.h"
#include "entity/SceneManager.h"
#include "tools/Log.h"
#include "entity/sprite/Sprite.h"
#include "entity/shapes/ColorRectangle.h"
#include "entity/demos/MenuDemo.h"


namespace MemoGL {
    #define EVENT_CALLBACK(x) std::bind(&x, this, std::placeholders::_1)

    GameEngine::GameEngine() {
        MEMOGL_LOG_TRACE("Game Engine initialized.")
        context = std::unique_ptr<IContext>(IContext::create(WindowSettings()));
        context->setEventCallBack(EVENT_CALLBACK(GameEngine::onEvent));
        graphicsEngine = std::make_unique<RasterizationEngine>(*context);
    }

    GameEngine::~GameEngine() {
        MEMOGL_LOG_TRACE("Game Engine has been deleted.");
    }

    void GameEngine::run() {
        if (!graphicsEngine) {
            throw std::runtime_error("Game Engine tried to run without graphics engine.");
        }


        std::shared_ptr<Scene> demo = std::make_shared<MenuDemo>();

        SceneManager* sceneManager = SceneManager::getInstance();
        sceneManager->load(demo);

        double lag = 0.0;
        double previous = context->getTime();
        double SECONDS_PER_UPDATE = 1.0 / 60.0;

        while (isRunning) {
            context->onUpdate();

            double current = context->getTime();
            double elapsed = current - previous;
            previous = current;

            lag += elapsed;

            while (lag >= SECONDS_PER_UPDATE) {
                // Game logic
                for (auto& layer : layerStack) {
                    layer->onUpdate();
                }

                lag -= SECONDS_PER_UPDATE;
            }

            // Rendering
            graphicsEngine->render(sceneManager->getCurrentScene(), (float)lag / SECONDS_PER_UPDATE);
        }

    }
    
    void GameEngine::pushLayer(Layer* layer) {
        layerStack.pushLayer(layer);
    }

    void GameEngine::pushOverlay(Layer* overlay) {
        layerStack.pushOverlay(overlay);
    }

    void GameEngine::onEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(EVENT_CALLBACK(GameEngine::onWindowClosed));
        propagateEventToLayers(e);
    }

    void GameEngine::propagateEventToLayers(Event& e) {
        for (auto it = layerStack.rbegin(); it != layerStack.rend(); ++it) {
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