#pragma once
#include "entity/sprite/Sprite.h"

namespace MemoGL {
    class Button : public Entity {
        public: 
            Button(const std::string& content);
            void update(float deltatime) override;
    };
}