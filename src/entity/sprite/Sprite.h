#pragma once
#include "../shapes/Rectangle.h"
#include "graphics/renderer/OpenGL/OpenGLRenderer.h"

namespace MemoGL {
    class Sprite : public Rectangle {
    public:
        void render() override;
        Sprite(const std::string filepath);

    private:
        std::shared_ptr<OpenGLTexture> texture;
        std::string texturepath;
    };
}