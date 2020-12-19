#pragma once
#include "../Demo.h"
#include "../SceneManager.h"
#include <vector>
#include <string>
#include <functional>

namespace MemoGL {
    class MenuDemo : public Demo {
        public: 
            MenuDemo();
            ~MenuDemo() override;

            void update(float deltatime) override;
            void render(IRenderer& renderer) override;
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