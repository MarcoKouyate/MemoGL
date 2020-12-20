#pragma once
#include "GL/glew.h"
#include <vector>

namespace MemoGL {
	class OpenGLIndexBuffer {
		public:
			void bind() const;
			void unbind() const;

			void push(std::vector<unsigned int> indices);

			inline unsigned int getCount() const { return count; }

			OpenGLIndexBuffer();
			~OpenGLIndexBuffer();

		private:
			unsigned int id;
			unsigned int count;
	};
}