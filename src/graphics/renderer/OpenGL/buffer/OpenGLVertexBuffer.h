#pragma once
#include "GL/glew.h"

namespace MemoGL {
	class OpenGLVertexBuffer {
		public:
			void bind() const;
			void unbind() const;

			OpenGLVertexBuffer(const void* data, unsigned int size);
			~OpenGLVertexBuffer();
		private:
			GLuint id;
	};
}