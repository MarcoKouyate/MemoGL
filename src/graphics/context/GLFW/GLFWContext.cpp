#include "GLFWContext.h"
#include <stdexcept>
#include <iostream>


namespace MemoGL {
    
    void ErrorCallback(int error, const char* description) {
        std::cerr << "Error : " << description << std::endl;
    }

    bool GLFWContext::isRunning() {
        return (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
    }

    void GLFWContext::close() {
        glfwTerminate();
        std::cout << "GLFW context has been closed." << std::endl;
    }

    void GLFWContext::init(const ContextSettings& properties) {
        std::cout << "Initializing GLFW context..." << std::endl;

        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwSetErrorCallback(ErrorCallback);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, properties.debugMode);
        //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, properties.version.major);
        //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, properties.version.minor);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        WindowSettings windowSettings = properties.window;
        window = glfwCreateWindow(properties.window.width, properties.window.height, properties.window.name, nullptr, nullptr);

        if (!window) {
            close();
            throw std::runtime_error("Failed to create the window");
        }

        glfwMakeContextCurrent(window);

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        std::cout << "GLFW context initialized." << std::endl;
    }




	GLFWContext::GLFWContext() {
        
	}

	GLFWContext::~GLFWContext() {
        close();
        std::cout << "GLFW Context has been deleted." << std::endl;
    }
}