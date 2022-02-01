#include "FontSceneDemo.h"
#include "imgui.h"
#include "entity/demos/MenuDemo.h"

namespace MemoGL {
    FontSceneDemo::FontSceneDemo() {
        //text = std::make_shared<Text>("On continue?");
        //this->addChild(text);
        
        paragraph = std::make_shared<Text>("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut molestie magna aliquet, varius purus sit amet, scelerisque ante. Sed quis auctor leo. Donec aliquam tellus et ultricies accumsan. Suspendisse eu magna facilisis, consectetur nisi quis, viverra tortor. Nunc a sagittis nulla. Etiam non lacus facilisis, rhoncus velit ac, auctor augue. Maecenas vel elit metus.", 10);
        

        this->addChild(paragraph);
        translationX = -5;
        translationY = 2.5;
        scaleX = 0.150;
        scaleY = 0.150;
        show_demo_window = false;
    }

    void FontSceneDemo::update(float deltatime)
    {
        paragraph->getTransform()->setPosition(translationX , translationY);
        paragraph->getTransform()->setScale(scaleX, scaleY);
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
