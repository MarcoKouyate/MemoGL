#include "../Scene.h"
#include "../sprite/Sprite.h"
#include "entity/texts/Text.h"

namespace MemoGL {
    class BasicSceneDemo : public Scene {
        public:
            BasicSceneDemo();
            virtual ~BasicSceneDemo() override = default;
            void imgui() override;
            void update(float deltatime) override;

        private:
            bool show_demo_window;
            
            float translationX;
            float translationY;

            std::shared_ptr<Sprite> sprite1;
            std::shared_ptr<Text> text;
    };
}