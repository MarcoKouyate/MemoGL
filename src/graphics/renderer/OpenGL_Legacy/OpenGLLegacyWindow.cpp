#include "OpenGLLegacyWindow.h"
#include <stdexcept>
#include <iostream>


namespace MemoGL {

    void ErrorCallback(int error, const char* description) {
        std::cerr << "Error : " << description << std::endl;
    }


    OpenGLLegacyWindow::OpenGLLegacyWindow(const WindowProperties& properties) {
        std::cout << "Initializing OpenGL Legacy window..." << std::endl;

        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        window = glfwCreateWindow(properties.width, properties.height, properties.name, nullptr, nullptr);

        if (!window) {
            glfwTerminate();
            throw std::runtime_error("Failed to initialize the window");
        }

        glfwMakeContextCurrent(window);

        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            glfwTerminate();
            throw std::runtime_error("Failed to initialize GLEW");
        }

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        std::cout << "OpenGL Legacy window initialized." << std::endl;
    }

    OpenGLLegacyWindow::~OpenGLLegacyWindow() {
        glfwTerminate();
        std::cout << "OpenGL Legacy window has been deleted." << std::endl;
    }

    bool OpenGLLegacyWindow::isRunning() {
        return (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
    }
}