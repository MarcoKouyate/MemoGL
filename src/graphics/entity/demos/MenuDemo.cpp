#include "MenuDemo.h"
#include "imgui.h"
#include "ClearColorDemo.h"
#include "BasicTextureDemo.h"

namespace MemoGL {
    void MenuDemo::update(float deltatime) {

    }

    void MenuDemo::render(IRenderer& renderer) {
        renderer.clearColor({ 0.0f, 0.0f, 0.0f, 0.0f });
        renderChildren(renderer);
    }

    void MenuDemo::imgui() {
        for (auto& demo : demos) {
            if (ImGui::Button(demo.first.c_str())) {
                currentDemo = demo.second();
                break;
            }
        }

        imguiChildren();
    }

    MenuDemo::MenuDemo(std::shared_ptr<Demo>& currentDemo) : currentDemo(currentDemo) {
        registerDemo<ClearColorDemo>("Clear Color");
        registerDemo<BasicTextureDemo>("BasicTexture");
    }

    MenuDemo::~MenuDemo() {

    }
}