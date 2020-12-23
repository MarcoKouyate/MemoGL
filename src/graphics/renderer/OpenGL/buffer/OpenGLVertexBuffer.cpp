#include "OpenGLVertexBuffer.h"
#include "../OpenGLError.h"
#include "tools/Log.h"

namespace MemoGL {
	void OpenGLVertexBuffer::push(std::vector<Vertex2D> vertices) {
		bind();
		GLCall(glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex2D), &vertices.front() , GL_STATIC_DRAW));
		unbind();
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer()
	{
		GLCall(glGenBuffers(1, &id));
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer() {
		MEMOGL_LOG_TRACE("Buffer deleted");
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