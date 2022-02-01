#pragma once
#include "entity/Scene.h"

namespace MemoGL {
    class ButtonSceneDemo : public Scene {
        public:
            ButtonSceneDemo();
            virtual ~ButtonSceneDemo() override = default;
            void imgui() override;
    };
}