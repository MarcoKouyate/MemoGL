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

    void OpenGLIndexBuffer::push(std::vector<unsigned int> indices) {
        ASSERT(sizeof(unsigned int) == sizeof(GLuint));
        count = indices.size();
        bind();
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), &indices.front(), GL_STATIC_DRAW));
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