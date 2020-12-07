#pragma once
#include "OpenGLVertexBuffer.h"
#include "OpenGLVertexLayout.h"
#include <memory>

namespace MemoGL {
    class OpenGLVertexArray {
        public:
            OpenGLVertexArray();
            ~OpenGLVertexArray();

            void bind() const;
            void unbind() const;
            void addBuffer(std::shared_ptr<OpenGLVertexBuffer> buffer, const OpenGLVertexLayout& layout);

        private:
            GLuint id;

    };
}