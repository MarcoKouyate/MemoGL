#pragma once
#include "graphics/buffer/Texture.h"

namespace MemoGL {
    class OpenGLTexture  {
        public:
            void bind(unsigned int slot = 0) const;
            void unbind() const;
            void init(const std::string& filepath);

            OpenGLTexture();
            ~OpenGLTexture();

        private:
            unsigned int id;
            std::string filepath;
            unsigned char* localBuffer;
            int width, height, bpp;
    };
}