#pragma once
#include "entity/sprite/Sprite.h"
#include "events/MouseEvents.h"

namespace MemoGL {
    class Button : public Entity {
        public: 
            Button(const std::string& content);
            void update(float deltatime) override;
            void onEvent(Event& e) override;

        private:
            bool OnMousePressed(MousePressedEvent& e);
            bool OnMouseReleased(MouseReleasedEvent& e);
    };
}