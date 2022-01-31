#include "Sprite.h"
#include "imgui.h"
#include "GameEngine.h"
#include "tools/Log.h"


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

    Sprite::Sprite(const Glyph& glyph, float scale) :
        Rectangle()
    {
        vertexShader = "res/shaders/texture2d.vert";
        fragmentShader = "res/shaders/font.frag";

        float height = glyph.size.y * scale;
        float width = glyph.size.x * scale;

        float offset = (glyph.size.y - glyph.bearing.y) * scale;

        float xpos = 0 + glyph.bearing.x * scale;
        float ypos = 0 - offset;

        vertices = {
            Vertex2D(glm::vec2(xpos, ypos), glm::vec2(0, 1), glm::vec3(1, 0, 0)),
            Vertex2D(glm::vec2(xpos + width, ypos), glm::vec2(1, 1), glm::vec3(0, 1, 0)),
            Vertex2D(glm::vec2(xpos + width, ypos + height), glm::vec2(1, 0), glm::vec3(0, 0, 1)),
            Vertex2D(glm::vec2(xpos, ypos + height), glm::vec2(0, 0), glm::vec3(1, 1, 1))
        };

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