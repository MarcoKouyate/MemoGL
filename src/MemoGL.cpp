#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"


namespace MemoGL{
    int main(int argc, char** argv) {
        glfwInit();
        glewInit();
        std::cout << "MemoGL.cpp" << std::endl;
        return 0;
    }
}
