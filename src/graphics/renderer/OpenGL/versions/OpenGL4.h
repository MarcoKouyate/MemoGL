#pragma once
#include "IOpenGLVersion.h"


namespace MemoGL {
	class OpenGL4 : public IOpenGLVersion {
	public:
		virtual void initErrorCalls() override;
	};

	void APIENTRY openglCallbackFunction(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam);
}