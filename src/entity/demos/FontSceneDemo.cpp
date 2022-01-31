#include "FontSceneDemo.h"
#include "imgui.h"
#include "entity/demos/MenuDemo.h"

namespace MemoGL {
    FontSceneDemo::FontSceneDemo() {
        text = std::make_shared<Text>("On continue?");
        this->addChild(text);
        translationX = -1;
        translationY = 0;
        scaleX = 0.5; 
        scaleY = 0.5;
        show_demo_window = true;
    }

    void FontSceneDemo::update(float deltatime)
    {
        text->getTransform()->setPosition(translationX , translationY);
        text->getTransform()->setScale(scaleX, scaleY);
    }

    void FontSceneDemo::imgui()
    {
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::Begin("Debug");
        ImGui::Checkbox("Demo Window", &show_demo_window);
        ImGui::SliderFloat("Translation X", &translationX, -1, 1);
        ImGui::SliderFloat("Translation Y", &translationY, -1, 1);

        ImGui::SliderFloat("ScaleX", &scaleX, -1, 1);
        ImGui::SliderFloat("ScaleY", &scaleY, -1, 1);


        if (ImGui::Button("< home")) {
            SceneManager::getInstance()->load(std::make_shared<MenuDemo>());
        }
        ImGui::End();
    }
}