#pragma once
#include "OpenGLVertexBuffer.h"
#include "graphics/buffer/VertexArray.h"
#include "graphics/buffer/Vertex2D.h"
#include "OpenGLIndexBuffer.h"
#include <memory>

namespace MemoGL {
    class OpenGLVertexArray : public VertexArray {
        public:
            OpenGLVertexArray();
            ~OpenGLVertexArray();

            void push(std::vector<Vertex2D> vertices, const unsigned int* indices, unsigned int count);

            void bind() const override;
            void unbind() const override;

        private:
            GLuint id;
            OpenGLIndexBuffer ibo;
    };
}