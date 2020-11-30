#include "OpenGLLegacyWindow.h"
#include <stdexcept>
#include <iostream>


namespace MemoGL {

    void ErrorCallback(int error, const char* description) {
        std::cerr << "Error : " << description << std::endl;
    }




    void OpenGLLegacyWindow::createContext(const WindowProperties& properties) {
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        window = glfwCreateWindow(properties.width, properties.height, properties.name, nullptr, nullptr);

        if (!window) {
            close();
            throw std::runtime_error("Failed to initialize the window");
        }

        glfwMakeContextCurrent(window);

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    }

    bool OpenGLLegacyWindow::isRunning() {
        return (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
    }

    void OpenGLLegacyWindow::close() {
        glfwTerminate();
        std::cout << "OpenGL Legacy window has been closed." << std::endl;
    }



    OpenGLLegacyWindow::OpenGLLegacyWindow(const WindowProperties& properties) {
        std::cout << "Initializing OpenGL Legacy window..." << std::endl;
        createContext(properties);
        std::cout << "OpenGL Legacy window initialized." << std::endl;
    }

    OpenGLLegacyWindow::~OpenGLLegacyWindow() {
        close();
        std::cout << "OpenGL Legacy window has been deleted." << std::endl;
    }
}