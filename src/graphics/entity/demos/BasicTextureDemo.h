#pragma once
#include "../Demo.h"
#include "../Object.h"

namespace MemoGL {
    class BasicTextureDemo : public Demo {
        public:
            BasicTextureDemo();
            ~BasicTextureDemo() override;

            void update(float deltatime) override;
            void render(IRenderer& renderer) override;
            void imgui() override;
    };
}