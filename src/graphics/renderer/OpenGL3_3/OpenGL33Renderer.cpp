#include "OpenGL33Renderer.h"
#include <iostream>


namespace MemoGL {
    OpenGL33Renderer::~OpenGL33Renderer() {
        release();
    }

    void OpenGL33Renderer::initialize(std::shared_ptr<IWindow> pWindow) {
        
        if (isInitialized) {
            release();
        }

        std::cout << "Initializing OpenGL 3.3 renderer..." << std::endl;

        window = pWindow;

        isInitialized = true;

        std::cout << "OpenGL 3.3 renderer initialized." << std::endl;

    }

    void OpenGL33Renderer::release() {
        if (isInitialized) {
            window = nullptr;

            isInitialized = false;
            std::cout << "OpenGL 3.3 renderer has been released." << std::endl;
        }
    }
}