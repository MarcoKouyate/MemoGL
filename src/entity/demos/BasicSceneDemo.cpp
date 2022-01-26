#include "BasicSceneDemo.h"
#include "../shapes/ColorRectangle.h"
#include "MenuDemo.h"
#include "imgui.h"
#include "tools/Log.h"
#include "events/inputs/Input.h"


namespace MemoGL {
    BasicSceneDemo::BasicSceneDemo() {
        std::shared_ptr<ColorRectangle> colorRect = std::make_shared<ColorRectangle>();
        sprite1 = std::make_shared<Sprite>("res/textures/memoticone_admiration.png");

        text = std::make_shared<Text>("Example");
        translationX = 0;
        translationY = 0;
        show_demo_window = true;
        this->addChild(colorRect);
        this->addChild(text);
        this->addChild(sprite1);
    }

    void BasicSceneDemo::update(float deltatime) {
        if (Input::get()->isKeyPressed(MEMOGL_KEY_TAB)) {
            MEMOGL_LOG_TRACE(deltatime);
        }
        text->setScale(translationX, translationY);
        sprite1->setScale(translationX, translationY);
    }

    void BasicSceneDemo::imgui() {
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::Begin("Debug");
        ImGui::Checkbox("Demo Window", &show_demo_window);
        ImGui::SliderFloat("Translation X", &translationX, -10, 10);
        ImGui::SliderFloat("Translation Y", &translationY, -10, 10);
        
        if (ImGui::Button("< home")) {
            SceneManager::getInstance()->load(std::make_shared<MenuDemo>());
        }
        ImGui::End();
    }
}