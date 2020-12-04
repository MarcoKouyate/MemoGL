#include "OpenGLError.h"



namespace MemoGL {


    void glClearErrors() {
        while (glGetError() != GL_NO_ERROR);
    }

    bool glLogErrors(const char* functionName, const char* file, int line)
    {
        while (GLenum error = glGetError()) {
            std::cout << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;
            std::cout << "[Error] (0x" << std::hex << error << "): ";
            std::cout << functionName << " " << file << ":" << std::dec << line << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;
            return false;
        }

        return true;
    }
}