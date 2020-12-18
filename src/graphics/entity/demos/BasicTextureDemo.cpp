#include "BasicTextureDemo.h"
#include "graphics/renderer/IRenderer.h"
#include "imgui.h"

namespace MemoGL {
    BasicTextureDemo::BasicTextureDemo() {

    }

    BasicTextureDemo::~BasicTextureDemo() {

    }

    void BasicTextureDemo::update(float deltatime) {
        
    }


    void BasicTextureDemo::render(IRenderer& renderer) {
        renderer.clearColor({ 0.5f, 0.5f, 0.3f, 1.0f });
        renderChildren(renderer);
    }


    void BasicTextureDemo::imgui() {
        ImGui::Text("Hello World");
        imguiChildren();
    }
}