#include "OpenGL33Error.h"

namespace MemoGL {
    void clearGlErrors() {
        while (glGetError() != GL_NO_ERROR);
    }

    bool logGlCalls(const char* functionName, const char* file, int line)
    {
        while (GLenum error = glGetError()) {
            std::cout << "[OpenGL Error] (0x" << std::hex << error << "): ";
            std::cout << functionName << " " << file << ":" << std::dec << line << std::endl;
            return false;
        }

        return true;
    }
}