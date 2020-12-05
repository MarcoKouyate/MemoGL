#include "OpenGLIndexBuffer.h"
#include "../OpenGLError.h"

namespace MemoGL {
	OpenGLIndexBuffer::OpenGLIndexBuffer(const unsigned int* data, unsigned int count) : 
		count (count)
	{
		ASSERT(sizeof(unsigned int) == sizeof(GLuint));

		GLCall(glGenBuffers(1, &id));
		bind();
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
		unbind();
	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer() {
		GLCall(glDeleteBuffers(1, &id));
	}
	void OpenGLIndexBuffer::bind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
	}
	void OpenGLIndexBuffer::unbind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}