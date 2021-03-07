#include "Sprite.h"
#include "imgui.h"
#include "GameEngine.h"


namespace MemoGL {
    Sprite::Sprite(const std::string& filepath) :
        Rectangle()
    {
        vertexShader = "res/shaders/texture2d.vert";
        fragmentShader = "res/shaders/texture2d.frag";
        renderer = GameEngine::get()->getGraphicsEngine()->getRenderer();
        texture = renderer->createTexture();
        texture->init(filepath);
    }

    Sprite::Sprite(const Glyph& glyph) :
        Rectangle() 
    {
        vertexShader = "res/shaders/texture2d.vert";
        fragmentShader = "res/shaders/texture2d.frag";
        renderer = GameEngine::get()->getGraphicsEngine()->getRenderer();
        texture = renderer->createTexture();
        texture->init(glyph);
    }

    void Sprite::render() {
        if (texture) {
            texture->bind();
        }

        Rectangle::render();

        if (texture) {
            texture->unbind();
        }
    }
}