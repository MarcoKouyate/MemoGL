#include "../Scene.h"

namespace MemoGL {
    class BasicSceneDemo : public Scene {
        public:
            BasicSceneDemo();
            virtual ~BasicSceneDemo() override = default;
            void imgui() override;
            void update(float deltatime) override;

        private:
            bool show_demo_window;
    };
}