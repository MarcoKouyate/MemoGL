#include "OpenGL33Renderer.h"
#include <iostream>


namespace MemoGL {
    OpenGL33Renderer::OpenGL33Renderer(std::shared_ptr<IWindow> pWindow) {
        window = pWindow;
        std::cout << "OpenGL 3.3 renderer initialized." << std::endl;
    }

    OpenGL33Renderer::~OpenGL33Renderer() {
        std::cout << "OpenGL 3.3 renderer has been released." << std::endl;
    }
}