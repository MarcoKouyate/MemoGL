#include "OpenGLError.h"
#include "tools/Log.h"



namespace MemoGL {


    void glClearErrors() {
        while (glGetError() != GL_NO_ERROR);
    }

    bool glLogErrors(const char* functionName, const char* file, int line)
    {
        while (GLenum error = glGetError()) {
            std::stringstream s;
            s << "(0x" << std::hex << error << "): ";
            s << functionName << " " << file << ":" << std::dec << line << std::endl;
            MEMOGL_LOG_ERROR(s.str());
            return false;
        }

        return true;
    }
}