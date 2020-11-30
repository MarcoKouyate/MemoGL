#include "OpenGL33Renderer.h"
#include <iostream>


namespace MemoGL {
    void OpenGL33Renderer::render() {
        glfwSwapBuffers(window->get());
    }

    OpenGL33Renderer::OpenGL33Renderer(std::shared_ptr<IWindow> pWindow) {
        window = pWindow;

        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            window->close();
            throw std::runtime_error("Failed to initialize GLEW");
        }

        std::cout << "OpenGL " << glGetString(GL_VERSION) << " renderer initialized." << std::endl;
    }

    OpenGL33Renderer::~OpenGL33Renderer() {
        std::cout << "OpenGL 3.3 renderer has been released." << std::endl;
    }
}