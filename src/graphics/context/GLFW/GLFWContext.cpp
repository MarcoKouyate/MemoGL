#include "GLFWContext.h"
#include <stdexcept>
#include "tools/Log.h"


namespace MemoGL {

    void ErrorCallback(int error, const char* description) {
        MEMOGL_LOG_ERROR(description);
    }

    bool GLFWContext::isRunning() {
        return (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
    }

    void GLFWContext::swapBuffers() {
        glfwSwapBuffers(window);
    }

    void GLFWContext::close() {
        glfwTerminate();
        MEMOGL_LOG_TRACE("GLFW context has been closed.");
    }

    double GLFWContext::getTime() {
        return glfwGetTime();
    }

    void GLFWContext::pollEvents() {
        glfwPollEvents();
    }


    void GLFWContext::init(ContextSettings* properties) {
        MEMOGL_LOG_TRACE("Initializing GLFW context...");

        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwSetErrorCallback(ErrorCallback);

        if (properties) {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, properties->version.majorId);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, properties->version.minorId);
            //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, properties->debugMode);
            glfwWindowHint(GLFW_OPENGL_PROFILE, getProfile(properties->profile));
            window = glfwCreateWindow(properties->window.width, properties->window.height, properties->window.name, nullptr, nullptr);
        }
        else {
            MEMOGL_LOG_TRACE(" --> dummy GLFW context...");
            window = glfwCreateWindow(10, 10, "Dummy Context", nullptr, nullptr);
        }

        if (!window) {
            close();
            throw std::runtime_error("Failed to create the window");
        }

        glfwMakeContextCurrent(window);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        
        MEMOGL_LOG_TRACE("GLFW context initialized.");
    }

    int GLFWContext::getProfile(APIProfile profile) {
        switch (profile) {
            case APIProfile::compatibility: return GLFW_OPENGL_COMPAT_PROFILE;
            case APIProfile::core: return GLFW_OPENGL_CORE_PROFILE;
        }

        return GLFW_OPENGL_ANY_PROFILE;
    }


	GLFWContext::GLFWContext() {
        
	}

	GLFWContext::~GLFWContext() {
        close();
        MEMOGL_LOG_TRACE("GLFW Context has been deleted.");
    }
}