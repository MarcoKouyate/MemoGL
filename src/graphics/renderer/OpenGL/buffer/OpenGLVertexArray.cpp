#include "OpenGLVertexArray.h"
#include "../OpenGLError.h"
#include "graphics/buffer/Vertex2D.h"


namespace MemoGL {
	OpenGLVertexArray::OpenGLVertexArray() {
		GLCall(glGenVertexArrays(1, &id));
		
	}

	OpenGLVertexArray::~OpenGLVertexArray() {
		GLCall(glDeleteVertexArrays(1, &id));
	}


	void OpenGLVertexArray::push(std::vector<Vertex2D> vertices, std::vector<unsigned int> indices) {
		GLCall(glBindVertexArray(id));
		OpenGLVertexBuffer vbo;
		vbo.push(vertices);
		vbo.bind();

		GLCall(glEnableVertexAttribArray(VERTEX_POSITION_ATTRIBUTE));
		GLCall(glVertexAttribPointer(VERTEX_POSITION_ATTRIBUTE, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (const void*)offsetof(Vertex2D, position)));

		GLCall(glEnableVertexAttribArray(VERTEX_TEXCOORDS_ATTRIBUTE));
		GLCall(glVertexAttribPointer(VERTEX_TEXCOORDS_ATTRIBUTE, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (const void*)offsetof(Vertex2D, textureCoordinates)));

		GLCall(glEnableVertexAttribArray(VERTEX_POSITION_ATTRIBUTE));
		GLCall(glVertexAttribPointer(VERTEX_COLOR_ATTRIBUTE, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (const void*)offsetof(Vertex2D, color)));

		vbo.unbind();
		ibo.push(indices);
		GLCall(glBindVertexArray(0));
	}

	void OpenGLVertexArray::bind() const
	{
		GLCall(glBindVertexArray(id));
		ibo.bind();
	}

	void OpenGLVertexArray::unbind() const
	{
		ibo.unbind();
		GLCall(glBindVertexArray(0));
	}
}