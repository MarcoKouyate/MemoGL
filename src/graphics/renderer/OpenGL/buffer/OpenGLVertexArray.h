#pragma once
#include "OpenGLVertexBuffer.h"
#include "OpenGLVertexLayout.h"
#include "graphics/entity/VertexArray.h"
#include <memory>

namespace MemoGL {
    class OpenGLVertexArray : public VertexArray {
        public:
            OpenGLVertexArray();
            ~OpenGLVertexArray();

            void bind() const override;
            void unbind() const override;
            void addBuffer(std::shared_ptr<OpenGLVertexBuffer> buffer, const OpenGLVertexLayout& layout);

        private:
            GLuint id;

    };
}