#pragma once
#include <vector>
#include "GL/glew.h"
#include "../OpenGLError.h"



namespace MemoGL {
    struct VertexBufferElement {
        unsigned int type;
        unsigned int count;
        unsigned int normalized;

        static unsigned int getSizeOfType(unsigned int type) {
            switch (type) {
            case GL_FLOAT:         return 4;
            case GL_UNSIGNED_INT:  return 4;
            case GL_UNSIGNED_BYTE: return 1;
            }

            ASSERT(false);
            return 0;
        }
    };

    class OpenGLVertexLayout {
    public:
        OpenGLVertexLayout() :
            stride(0) 
        {}

        template<typename T>
        void push(unsigned int count) {
            static_assert(false);
        }

        template<>
        void push<float>(unsigned int count) {
            elements.push_back({ GL_FLOAT, count, GL_FALSE });
            stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
        }

        template<>
        void push<unsigned int>(unsigned int count) {
            elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
            stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
        }

        template<>
        void push<unsigned char>(unsigned int count) {
            elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
            stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
        }

        inline unsigned int getStride() const { return stride; }
        inline const std::vector<VertexBufferElement>& getElements() const { return elements; }

    private:
        std::vector<VertexBufferElement> elements;
        unsigned int stride;
    };
}