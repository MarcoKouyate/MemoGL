#include "OpenGL4Error.h"

namespace MemoGL {
    void glClearErrors() {
        while (glGetError() != GL_NO_ERROR);
    }

    bool glLogErrors(const char* functionName, const char* file, int line)
    {
        while (GLenum error = glGetError()) {
            std::cout << "[OpenGL Error] (0x" << std::hex << error << "): ";
            std::cout << functionName << " " << file << ":" << std::dec << line << std::endl;
            return false;
        }

        return true;
    }
}