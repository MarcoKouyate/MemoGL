#include "ButtonSceneDemo.h"
#include "imgui.h"
#include "entity/SceneManager.h"
#include "MenuDemo.h"
#include "entity/buttons/Button.h"

namespace MemoGL {
    ButtonSceneDemo::ButtonSceneDemo() {
        std::shared_ptr<Button> button = std::make_shared<Button>("This is the best button you could have");
        this->addChild(button);
    }

    void ButtonSceneDemo::imgui()
    {
        ImGui::Begin("Debug");

        if (ImGui::Button("< home")) {
            SceneManager::getInstance()->load(std::make_shared<MenuDemo>());
        }
        ImGui::End();
    }
}