#pragma once
#include "../Demo.h"
#include <vector>
#include <string>
#include <functional>

namespace MemoGL {
    class MenuDemo : public Demo {
        public: 
            MenuDemo(std::shared_ptr<Demo>& currentDemo);
            ~MenuDemo() override;

            void update(float deltatime) override;
            void render(IRenderer& renderer) override;
            void imgui() override;

            template<typename T>
            void registerDemo(const std::string& name) {

                    demos.push_back(
                        std::make_pair(name, []() { return std::make_shared<T>(); }));
            }

        private:
            std::shared_ptr<Demo>& currentDemo;
            std::vector<std::pair<std::string, std::function<std::shared_ptr<Demo>()>>> demos;
    };
}