#pragma once
#include "../Scene.h"
#include "../Object.h"

namespace MemoGL {
    class BasicTextureDemo : public Scene {
        public:
            BasicTextureDemo();
            ~BasicTextureDemo() override;

            void update(float deltatime) override;
            void render() override;
            void imgui() override;
        private:
            float clearColor[4];
    };
}