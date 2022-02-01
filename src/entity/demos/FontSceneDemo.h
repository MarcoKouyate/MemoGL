#pragma once
#include "entity/Scene.h"
#include "entity/texts/Text.h"

namespace MemoGL {
    class FontSceneDemo : public Scene{
    public:
        FontSceneDemo();
        virtual ~FontSceneDemo() override = default;
        void imgui() override;
        void update(float deltatime) override;

    private:
        std::shared_ptr<Text> text;
        std::shared_ptr<Text> paragraph;
        bool show_demo_window;

        float translationX;
        float translationY;

        float scaleX;
        float scaleY;
    };
}
