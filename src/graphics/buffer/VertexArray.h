#pragma once
#include <vector>
#include "Vertex2D.h"


namespace MemoGL {
    class VertexArray {
        public:
            virtual ~VertexArray() = default;

            virtual void push(std::vector<Vertex2D> vertices, std::vector<unsigned int> indices) = 0;

            virtual void bind() const = 0;
            virtual void unbind() const = 0;
    };
}