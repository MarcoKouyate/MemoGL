#include "OpenGLIndexBuffer.h"
#include "../OpenGLError.h"

namespace MemoGL {
    OpenGLIndexBuffer::OpenGLIndexBuffer() : 
        count (0)
    {
        GLCall(glGenBuffers(1, &id));
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer() {
        GLCall(glDeleteBuffers(1, &id));
    }

    void OpenGLIndexBuffer::push(const unsigned int* data, unsigned int count) {
        ASSERT(sizeof(unsigned int) == sizeof(GLuint));

        bind();
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
        unbind();
    }

    void OpenGLIndexBuffer::bind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
    }

    void OpenGLIndexBuffer::unbind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }
}