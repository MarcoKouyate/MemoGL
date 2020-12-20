#pragma once
#include "GL/glew.h"
#include "graphics/buffer/Vertex2D.h"
#include <vector>

namespace MemoGL {
	class OpenGLVertexBuffer {
		public:
			void push(std::vector<Vertex2D> vertices);

			void bind() const;
			void unbind() const;

			OpenGLVertexBuffer();
			~OpenGLVertexBuffer();
		private:
			GLuint id;
	};
}