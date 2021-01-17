#include "BasicSceneDemo.h"
#include "../shapes/ColorRectangle.h"
#include "../sprite/Sprite.h"
#include "MenuDemo.h"
#include "imgui.h"
#include "tools/Log.h"
#include "events/inputs/Input.h"

namespace MemoGL {
    BasicSceneDemo::BasicSceneDemo() {
        std::shared_ptr<ColorRectangle> colorSprite = std::make_shared<ColorRectangle>();
        std::shared_ptr<Sprite> textureSprite = std::make_shared<Sprite>();
        this->addChild(colorSprite);
        this->addChild(textureSprite);
        show_demo_window = true;
    }

    void BasicSceneDemo::update(float deltatime) {
        if (Input::get()->isKeyPressed(MEMOGL_KEY_TAB)) {
            MEMOGL_LOG_TRACE(deltatime);
        }
    }

    void BasicSceneDemo::imgui() {
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::Begin("Debug");
        ImGui::Checkbox("Demo Window", &show_demo_window);
        
        if (ImGui::Button("< home")) {
            SceneManager::getInstance()->load(std::make_shared<MenuDemo>());
        }
        ImGui::End();
    }
}