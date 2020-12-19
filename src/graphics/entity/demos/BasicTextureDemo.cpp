#include "BasicTextureDemo.h"
#include "graphics/renderer/IRenderer.h"
#include "imgui.h"
#include "../demos/MenuDemo.h"

namespace MemoGL {
    BasicTextureDemo::BasicTextureDemo() : clearColor{ 0.1f, 0.1f, 0.1f, 1.0f } {

    }

    BasicTextureDemo::~BasicTextureDemo() {

    }

    void BasicTextureDemo::update(float deltatime) {
        
    }


    void BasicTextureDemo::render(IRenderer& renderer) {
        renderer.clearColor({ clearColor[0], clearColor[1], clearColor[2], clearColor[3] });
        renderChildren(renderer);
    }


    void BasicTextureDemo::imgui() {
        ImGui::Begin("Basic Texture Demo");
        ImGui::Text("Hello World");
        ImGui::ColorEdit4("Clear Color", clearColor);

        if (ImGui::Button("< home")) {
            SceneManager::getInstance()->load(std::make_shared<MenuDemo>());
        }

        ImGui::End();
        imguiChildren();
    }
}