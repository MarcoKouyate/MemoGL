#pragma once
#include "pch.h"
#include "GL/glew.h"

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