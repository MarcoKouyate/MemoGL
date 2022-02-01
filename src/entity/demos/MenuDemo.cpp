#include "MenuDemo.h"
#include "imgui.h"
#include "ClearColorDemo.h"
#include "BasicTextureDemo.h"
#include "BasicSceneDemo.h"
#include "FontSceneDemo.h"
#include "ButtonSceneDemo.h"
#include "GameEngine.h"

namespace MemoGL {
    void MenuDemo::update(float deltatime) {

    }

    void MenuDemo::render() {
        std::shared_ptr<IRenderer> renderer = GameEngine::get()->getGraphicsEngine()->getRenderer();
        renderer->clearColor({ 0.0f, 0.0f, 0.0f, 0.0f });
    }

    void MenuDemo::imgui() {
        for (auto& demo : demos) {
            if (ImGui::Button(demo.first.c_str())) {
                demo.second();
                break;
            }
        }
    }

    MenuDemo::MenuDemo() {
        registerDemo<ClearColorDemo>("Clear Color");
        registerDemo<BasicTextureDemo>("Basic Texture");
        registerDemo<BasicSceneDemo>("Basic Scene Demo");
        registerDemo<FontSceneDemo>("Font Scene Demo");
        registerDemo<ButtonSceneDemo>("Button Scene Demo");
    }

    MenuDemo::~MenuDemo() {

    }
}