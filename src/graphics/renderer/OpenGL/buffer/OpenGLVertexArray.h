#pragma once
#include "pch.h"
#include "OpenGLVertexBuffer.h"
#include "graphics/buffer/VertexArray.h"
#include "graphics/buffer/Vertex2D.h"
#include "OpenGLIndexBuffer.h"

namespace MemoGL {
    class OpenGLVertexArray : public VertexArray {
        public:
            OpenGLVertexArray();
            ~OpenGLVertexArray();

            void push(std::vector<Vertex2D> vertices, std::vector<unsigned int> indices) override;

            void bind() const override;
            void unbind() const override;

        private:
            GLuint id;
            OpenGLIndexBuffer ibo;

            const GLuint VERTEX_POSITION_ATTRIBUTE = 0;
            const GLuint VERTEX_TEXCOORDS_ATTRIBUTE = 1;
            const GLuint VERTEX_COLOR_ATTRIBUTE = 2;
    };
}