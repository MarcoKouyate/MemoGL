#include "OpenGL33Window.h"
#include <stdexcept>
#include <iostream>


namespace MemoGL {
    
    void ErrorCallback(int error, const char* description) {
        std::cerr << "Error : " << description << std::endl;
    }


	OpenGL33Window::OpenGL33Window(const WindowProperties& properties) {
        std::cout << "Initializing OpenGL 3.3 window..." << std::endl;

        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwSetErrorCallback(ErrorCallback);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

        std::cout << "OpenGL 3.3 window initialized." << std::endl;
	}

	OpenGL33Window::~OpenGL33Window() {
        glfwTerminate();
        std::cout << "OpenGL 3.3 window has been deleted." << std::endl;
    }

    bool OpenGL33Window::isRunning() {
        return (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
    }
}