#pragma once

#include "graphics/rasterization/RasterizationEngine.h"
#include "events/WindowEvents.h"
#include "entity/EntityStack.h"
#include "entity/Scene.h"

namespace MemoGL {
    class GameEngine {
        public:
            void run();
            void onEvent(Event& e);
            
            void loadScene(std::shared_ptr<Scene> scene);
            
            ~GameEngine();

            virtual inline const IWindow& getContext() const {
                return *context;
            }

            static GameEngine* get();
            
            std::shared_ptr<IGraphicsEngine> getGraphicsEngine() const {
                return graphicsEngine;
            }

        private:
            GameEngine();
            static GameEngine* instance;

            void checkActiveScene();
            void update();
            void render();

            bool onWindowClosed(WindowCloseEvent& e);
            void propagateEventToLayers(Event& e);
            void loadEntity(std::shared_ptr<Entity> entity);

            EntityStack entityStack;

            bool isRunning = true;
            std::unique_ptr<IWindow> context = nullptr;
            std::shared_ptr<IGraphicsEngine> graphicsEngine = nullptr;
            std::shared_ptr<Scene> loadedScene = nullptr;

            double lag;
            double previous;
            const double SECONDS_PER_UPDATE = 1.0 / 60.0;
    };
}