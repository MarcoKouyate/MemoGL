#include "OpenGL33Window.h"
#include <stdexcept>
#include <iostream>


namespace MemoGL {
    
    void ErrorCallback(int error, const char* description) {
        std::cerr << "Error : " << description << std::endl;
    }

	OpenGL33Window::~OpenGL33Window() {
		release();
	}

	void OpenGL33Window::initialize(int width, int height, const char* name) {
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwSetErrorCallback(ErrorCallback);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, name, nullptr, nullptr);

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
	}

	void OpenGL33Window::release() {
        glfwTerminate();
        window = nullptr;
        std::cout << "OpenGL 3.3  window has been released" << std::endl;
    }
}