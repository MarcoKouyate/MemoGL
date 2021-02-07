#include "../Scene.h"
#include "../sprite/Sprite.h"

namespace MemoGL {
    class BasicSceneDemo : public Scene {
        public:
            BasicSceneDemo();
            virtual ~BasicSceneDemo() override = default;
            void imgui() override;
            void update(float deltatime) override;

        private:
            bool show_demo_window;
            std::shared_ptr<Sprite> textureSprite;

            float translationX;
            float translationY;
    };
}