#include "OpenGL33Renderer.h"
#include <iostream>


namespace MemoGL {
    OpenGL33Renderer::~OpenGL33Renderer() {
        release();
    }

    void OpenGL33Renderer::initialize(const RendererType& renderertype, const WindowProperties& windowProperties) {
        
        if (isInitialized) {
            release();
        }

        std::cout << "Initializing OpenGL 3.3 renderer..." << std::endl;

        m_window.initialize(windowProperties);
        window = &m_window;

        isInitialized = true;

        std::cout << "OpenGL 3.3 renderer initialized." << std::endl;

    }

    void OpenGL33Renderer::release() {
        if (isInitialized) {
            m_window.release();
            window = nullptr;

            isInitialized = false;
            std::cout << "OpenGL 3.3 renderer has been released." << std::endl;
        }
    }
}