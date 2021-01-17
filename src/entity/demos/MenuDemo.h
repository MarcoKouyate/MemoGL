#pragma once
#include "../Scene.h"
#include "../SceneManager.h"


namespace MemoGL {
    class MenuDemo : public Scene {
        public: 
            MenuDemo();
            ~MenuDemo() override;

            void update(float deltatime) override;
            void render() override;
            void imgui() override;

            template<typename T>
            void registerDemo(const std::string& name) {

                    demos.push_back(
                        std::make_pair(name, []() { SceneManager::getInstance()->load(std::make_shared<T>()); }));
            }

        private:
            std::vector<std::pair<std::string, std::function<void()>>> demos;
    };
}