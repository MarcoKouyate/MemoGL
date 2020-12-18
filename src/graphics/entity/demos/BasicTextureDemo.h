#pragma once
#include "../Demo.h"
#include "../Object.h"

namespace MemoGL {
    class BasicTextureDemo : public IDemo {
        public:
            BasicTextureDemo();
            ~BasicTextureDemo();

            void addChild(std::shared_ptr<Object> object);

            void update(float deltatime) override;
            void render(IRenderer& renderer) override;
            void imgui() override;
        
    private:
            std::shared_ptr<Object> sprite;
    };
}