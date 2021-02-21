#include "OpenGLTexture.h"
#include "../OpenGLError.h"
#include "stb_image.h"
#include "tools/Log.h"

namespace MemoGL {
    OpenGLTexture::OpenGLTexture() :
        id(0),  filepath(""), localBuffer(nullptr), width(0), height(0), bpp(0)
    {}

    void OpenGLTexture::init(const std::string& filepath) {
        GLCall(glGenTextures(1, &id));
        bind();

        //mandatory parameters
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

        stbi_set_flip_vertically_on_load(1);
        localBuffer = stbi_load(filepath.c_str(), &width, &height, &bpp, 4);

        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
        unbind();

        if (localBuffer) {
            stbi_image_free(localBuffer);
        }
        else {
            MEMOGL_LOG_ERROR("no data found for texture: {0}", filepath);
        }
    }

    void OpenGLTexture::bind(unsigned int slot /*= 0*/) const {
        GLCall(glActiveTexture(GL_TEXTURE0 + slot));
        GLCall(glBindTexture(GL_TEXTURE_2D, id));
    }

    void OpenGLTexture::unbind() const {
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));
    }

    OpenGLTexture::~OpenGLTexture() {
        GLCall(glDeleteTextures(1, &id));
    }
}