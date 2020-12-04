#include "OpenGL4.h" 
#include "../OpenGLError.h"




namespace MemoGL {
    void APIENTRY openglCallbackFunction(GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        const void* userParam) {

#ifdef _DEBUG
        std::cout << std::endl;
        std::cout << "--------------------- OpenGL 4.X Error start----------------" << std::endl;
        std::cout << "[type] ";
        switch (type) {
        case GL_DEBUG_TYPE_ERROR:
            std::cout << "ERROR";
            break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            std::cout << "DEPRECATED_BEHAVIOR";
            break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            std::cout << "UNDEFINED_BEHAVIOR";
            break;
        case GL_DEBUG_TYPE_PORTABILITY:
            std::cout << "PORTABILITY";
            break;
        case GL_DEBUG_TYPE_PERFORMANCE:
            std::cout << "PERFORMANCE";
            break;
        case GL_DEBUG_TYPE_OTHER:
            std::cout << "OTHER";
            break;
        }
        std::cout << std::endl;

        std::cout << "[id] " << id << std::endl;
        std::cout << "[severity] ";
        switch (severity) {
        case GL_DEBUG_SEVERITY_LOW:
            std::cout << "LOW";
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            std::cout << "MEDIUM";
            break;
        case GL_DEBUG_SEVERITY_HIGH:
            std::cout << "HIGH";
            break;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "[message] " << message << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
#endif
    }

    void OpenGL4::changeSettings(ContextSettings& settings) {
        settings.debugMode = true;
        settings.version.major = 4;
        settings.version.minor = 1;
    }

	void OpenGL4::initErrorCalls() {
        if (glDebugMessageCallback) {
            std::cout << "Register OpenGL debug callback " << std::endl;
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(openglCallbackFunction, nullptr);
            GLuint unusedIds = 0;
            glDebugMessageControl(GL_DONT_CARE,
                GL_DONT_CARE,
                GL_DONT_CARE,
                0,
                &unusedIds,
                true);
        }
        else
            std::cout << "glDebugMessageCallback not available" << std::endl;
	}
}