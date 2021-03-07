#pragma once
#include "graphics/buffer/Texture.h"
#include "graphics/text/Glyph.h"

namespace MemoGL {
    class OpenGLTexture  {
        public:
            void bind(unsigned int slot = 0) const;
            void unbind() const;
            void init(const std::string& filepath);
            void init(const Glyph glyph);

            OpenGLTexture();
            ~OpenGLTexture();

        private:
            unsigned int id;
            std::string filepath;
            unsigned char* localBuffer;
            int width, height, bpp;
    };
}