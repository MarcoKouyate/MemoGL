#pragma once
#include "../shapes/Rectangle.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"
#include "graphics/text/Glyph.h"

namespace MemoGL {
    class Sprite : public Rectangle {
    public:
        void render() override;
        Sprite(const std::string& filepath);
        Sprite(const Glyph& glyph);

    private:
        std::shared_ptr<OpenGLTexture> texture;
        std::shared_ptr<IRenderer> renderer;
    };
}