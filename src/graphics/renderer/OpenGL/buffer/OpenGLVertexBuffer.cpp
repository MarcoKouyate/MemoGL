#include "OpenGLVertexBuffer.h"
#include "../OpenGLError.h"

namespace MemoGL {
	OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, unsigned int size)
	{
		GLCall(glGenBuffers(1, &id));
		bind();
		GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		unbind();
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer() {
		std::cout << "Buffer deleted" << std::endl;
		GLCall(glDeleteBuffers(1, &id));
	}
	void OpenGLVertexBuffer::bind() const
	{
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, id));
	}
	void OpenGLVertexBuffer::unbind() const
	{
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}