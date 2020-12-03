#include "OpenGL4Window.h"
#include <stdexcept>
#include <iostream>


namespace MemoGL {
    
    void ErrorCallback(int error, const char* description) {
        std::cerr << "Error : " << description << std::endl;
    }

    bool OpenGL4Window::isRunning() {
        return (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
    }

    void OpenGL4Window::close() {
        glfwTerminate();
        std::cout << "OpenGL 3.3 window has been closed." << std::endl;
    }

    void OpenGL4Window::createContext(const WindowProperties& properties) {

        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwSetErrorCallback(ErrorCallback);
        glfwWindowHint(GLFW_SAMPLES, 4);
        //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(properties.width, properties.height, properties.name, nullptr, nullptr);

        if (!window) {
            close();
            throw std::runtime_error("Failed to initialize the window");
        }

        glfwMakeContextCurrent(window);

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    }


	OpenGL4Window::OpenGL4Window(const WindowProperties& properties) {
        std::cout << "Initializing OpenGL 3.3 window..." << std::endl;
        createContext(properties);
        std::cout << "OpenGL 3.3 window initialized." << std::endl;
	}

	OpenGL4Window::~OpenGL4Window() {
        close();
        std::cout << "OpenGL 3.3 window has been deleted." << std::endl;
    }
}