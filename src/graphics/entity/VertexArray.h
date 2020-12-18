#pragma once

namespace MemoGL {
    class VertexArray {
        public:
            virtual ~VertexArray() = default;

            virtual void bind() const = 0;
            virtual void unbind() const = 0;
    };
}