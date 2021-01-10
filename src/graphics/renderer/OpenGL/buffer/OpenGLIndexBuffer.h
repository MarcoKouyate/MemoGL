#pragma once
#include "GL/glew.h"

namespace MemoGL {
	class OpenGLIndexBuffer {
		public:
			void bind() const;
			void unbind() const;

			void push(std::vector<unsigned int> indices);

			inline size_t getCount() const { return count; }

			OpenGLIndexBuffer();
			~OpenGLIndexBuffer();

		private:
			unsigned int id;
			size_t count;
	};
}