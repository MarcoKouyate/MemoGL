#pragma once

namespace MemoGL {
    class OpenGLTexture {
        public:
            void bind(unsigned int slot = 0) const;
            void unbind() const;

            OpenGLTexture(const std::string& filepath);
            ~OpenGLTexture();

        private:
            unsigned int id;
            std::string filepath;
            unsigned char* localBuffer;
            int width, height, bpp;
    };
}