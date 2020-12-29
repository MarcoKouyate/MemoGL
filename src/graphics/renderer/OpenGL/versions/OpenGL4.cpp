#include "OpenGL4.h" 
#include "../OpenGLError.h"
#include "tools/Log.h"



namespace MemoGL {
    void APIENTRY openglCallbackFunction(GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        const void* userParam) {

#ifdef _DEBUG
        std::string typeString;
        std::string severityString;

        switch (type) {
        case GL_DEBUG_TYPE_ERROR:
            typeString = "ERROR";
            break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            typeString = "DEPRECATED_BEHAVIOR";
            break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            typeString = "UNDEFINED_BEHAVIOR";
            break;
        case GL_DEBUG_TYPE_PORTABILITY:
            typeString = "PORTABILITY";
            break;
        case GL_DEBUG_TYPE_PERFORMANCE:
            typeString = "PERFORMANCE";
            break;
        case GL_DEBUG_TYPE_OTHER:
            typeString = "OTHER";
            break;
        }

        switch (severity) {
        case GL_DEBUG_SEVERITY_LOW:
            severityString = "LOW";
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            severityString = "MEDIUM";
            break;
        case GL_DEBUG_SEVERITY_HIGH:
            severityString = "HIGH";
            break;
        default:
            severityString = "NONE";
        }

        std::string logMessage = "--------------------- OpenGL 4.X Error start----------------\n"  
                                 "[type] " + typeString + " [id] {0} [severity] " +  severityString + "\n\n"
                                 "[message] " + message + "\n"
                                 "------------------------------------------------------------";
        switch (severity) {
            case GL_DEBUG_SEVERITY_HIGH:
                MEMOGL_LOG_ERROR(logMessage.c_str(), id);
                break;
            case GL_DEBUG_SEVERITY_MEDIUM:
            case GL_DEBUG_SEVERITY_LOW:
                MEMOGL_LOG_WARNING(logMessage.c_str(), id);
                break;
            //default: MEMOGL_LOG_TRACE(logMessage.c_str(), id);
        }
#endif
    }


	void OpenGL4::initErrorCalls() {
        if (glDebugMessageCallback) {
            MEMOGL_LOG_TRACE("Register OpenGL debug callback");
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
           MEMOGL_LOG_TRACE("glDebugMessageCallback not available");
	}
}