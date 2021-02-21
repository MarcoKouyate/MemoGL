#include "Sprite.h"
#include "imgui.h"
#include "GameEngine.h"


namespace MemoGL {
    Sprite::Sprite(const std::string filepath) :
        Rectangle()
    {
        vertexShader = "res/shaders/texture2d.vert";
        fragmentShader = "res/shaders/texture2d.frag";
        texturepath = filepath;
    }

    void Sprite::render() {
        std::shared_ptr<IRenderer> renderer = GameEngine::get()->getGraphicsEngine()->getRenderer();

        if (!texture) {
            texture = renderer->createTexture();
            texture->init(texturepath);
        }

        if (texture) {
            texture->bind();
        }

        Rectangle::render();

        if (texture) {
            texture->unbind();
        }
    }
}