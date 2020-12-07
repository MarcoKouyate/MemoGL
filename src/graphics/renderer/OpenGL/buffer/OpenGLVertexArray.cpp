#include "OpenGLVertexArray.h"
#include "../OpenGLError.h"

namespace MemoGL {
	OpenGLVertexArray::OpenGLVertexArray() {
		GLCall(glGenVertexArrays(1, &id));
		
	}

	OpenGLVertexArray::~OpenGLVertexArray() {
		GLCall(glDeleteVertexArrays(1, &id));
	}

	void OpenGLVertexArray::bind() const
	{
		GLCall(glBindVertexArray(id));
	}

	void OpenGLVertexArray::unbind() const
	{
		GLCall(glBindVertexArray(0));
	}

	void OpenGLVertexArray::addBuffer(std::shared_ptr<OpenGLVertexBuffer> buffer, const OpenGLVertexLayout& layout) {
		bind();
		buffer->bind();
		const auto& elements = layout.getElements();
		unsigned int offset = 0;

		for (unsigned int i = 0; i < elements.size(); i++) {
			const auto& element = elements[i];
			GLCall(glEnableVertexAttribArray(i));
			GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*) offset));
			offset += element.count * VertexBufferElement::getSizeOfType(element.type);
		}

		buffer->unbind();
		unbind();
	}
}