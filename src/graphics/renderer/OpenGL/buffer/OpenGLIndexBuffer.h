#pragma once
#include "GL/glew.h"

namespace MemoGL {
	class OpenGLIndexBuffer {
		public:
			void bind() const;
			void unbind() const;

			inline unsigned int getCount() const { return count; }

			OpenGLIndexBuffer(const unsigned int* data, unsigned int count);
			~OpenGLIndexBuffer();

		private:
			unsigned int id;
			unsigned int count;
	};
}