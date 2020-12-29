#include "GLFWContext.h"
#include <stdexcept>
#include "tools/Log.h"


namespace MemoGL {

    bool GLFWContext::GLFW_initialized = false;

    IContext* IContext::create(const ContextSettings& properties) {
        return new GLFWContext(properties);
    }

    void ErrorCallback(int error, const char* description) {
        MEMOGL_LOG_ERROR(description);
    }

    bool GLFWContext::isRunning() {
        return (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
    }

    void GLFWContext::close() {
        glfwDestroyWindow(window);
        //TODO: Terminate glfw at system shutdown;
        //glfwTerminate();
        MEMOGL_LOG_TRACE("GLFW context has been closed.");
    }

    double GLFWContext::getTime() {
        return glfwGetTime();
    }

    void GLFWContext::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Init
    void GLFWContext::init(const ContextSettings& properties) {
        windowData.title = properties.window.name;
        windowData.width = properties.window.width;
        windowData.height = properties.window.height;

        MEMOGL_LOG_TRACE("Initializing GLFW context : window {0} ({1}, {2})", windowData.title, windowData.width, windowData.height);

        if (!GLFW_initialized) {
            int success = glfwInit();
            MEMOGL_ASSERT(success, "Failed to initialize GLFW");
            //throw std::runtime_error("Failed to initialize GLFW");
            GLFW_initialized = true;
        }

        glfwSetErrorCallback(ErrorCallback);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, properties.version.majorId);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, properties.version.minorId);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, properties.debugMode);
        glfwWindowHint(GLFW_OPENGL_PROFILE, getProfile(properties.profile));
        window = glfwCreateWindow(properties.window.width, properties.window.height, properties.window.name, nullptr, nullptr);

        if (!window) {
            close();
            throw std::runtime_error("Failed to create the window");
        }

        glfwMakeContextCurrent(window);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glfwSetWindowUserPointer(window, &windowData);
        setVSync(true);
        
        MEMOGL_LOG_TRACE("GLFW context initialized.");
    }

    int GLFWContext::getProfile(APIProfile profile) {
        switch (profile) {
            case APIProfile::compatibility: return GLFW_OPENGL_COMPAT_PROFILE;
            case APIProfile::core: return GLFW_OPENGL_CORE_PROFILE;
        }

        return GLFW_OPENGL_ANY_PROFILE;
    }

    // getters
    unsigned int GLFWContext::getWidth() const {
        return windowData.width;
    }
    unsigned int GLFWContext::getHeight() const {
        return windowData.height;
    }

    bool GLFWContext::isVSync() const {
        return windowData.vSync;
    }


    // setters
    void GLFWContext::setVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        }
        else {
            glfwSwapInterval(0);
        }

        windowData.vSync = enabled;
    }

    void GLFWContext::setEventCallBack(const EventCallBackFunction& callback) {
        windowData.eventCallback = callback;
    }


    // constructors
	GLFWContext::GLFWContext(const ContextSettings& properties) {
        init(properties);
	}

	GLFWContext::~GLFWContext() {
        close();
        MEMOGL_LOG_TRACE("GLFW Context has been deleted.");
    }
}