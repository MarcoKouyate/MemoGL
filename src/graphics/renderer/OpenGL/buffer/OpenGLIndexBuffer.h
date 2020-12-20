#pragma once
#include "GL/glew.h"

namespace MemoGL {
	class OpenGLIndexBuffer {
		public:
			void bind() const;
			void unbind() const;

			void push(const unsigned int* data, unsigned int count);

			inline unsigned int getCount() const { return count; }

			OpenGLIndexBuffer();
			~OpenGLIndexBuffer();

		private:
			unsigned int id;
			unsigned int count;
	};
}