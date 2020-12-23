#include "OpenGLRenderer.h"
#include "OpenGLError.h"

#include "graphics/buffer/Vertex2D.h"
#include "tools/File.h"
#include "graphics/context/GLFW/GLFWContext.h"
#include "glm/glm.hpp"

#include "tools/Log.h"


namespace MemoGL {
    // INITIALIZATION
    void OpenGLRenderer::init() {
        initializeWindow();
        initializeGlew();
        initializeTextures();
        initializeImGui();
    }

    void OpenGLRenderer::initializeWindow() {
        // an opengl context is required in order to query client opengl version
        // which is why we create a dummy context and close it after getting the opengl version
        context->init(nullptr);
        openGLVersion = getOpenGLVersion();
        context->close();

        ContextSettings properties;
        properties.window = WindowSettings(1280, 720, "MemoGL");
        properties.profile = APIProfile::core;
        
        openGLVersion->changeSettings(properties);
        context->init(&properties);
    }

    std::unique_ptr<IOpenGLVersion> OpenGLRenderer::getOpenGLVersion() {
        int major;
        int minor;
        glGetIntegerv(GL_MAJOR_VERSION, &major);
        glGetIntegerv(GL_MINOR_VERSION, &minor);

        if (major >= 4 && minor >= 3) {
            return std::make_unique<OpenGL4>();
        }
        else {
            return std::make_unique<OpenGL3>();
        }
    }

    void OpenGLRenderer::initializeGlew() {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            context->close();
            throw std::runtime_error("Failed to initialize GLEW");
        }

        openGLVersion->initErrorCalls();
    }

    void OpenGLRenderer::initializeTextures() {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        
        texture = std::make_unique<OpenGLTexture>("res/textures/memoticone_admiration.png");
        texture->bind();
    }

    std::shared_ptr<VertexArray> OpenGLRenderer::createVertexArray() {
        return std::make_shared<OpenGLVertexArray>();
    }


    void OpenGLRenderer::initializeImGui() {
        imgui = std::make_unique<OpenGLImGui>(context, "#version 330", true);
    }

    std::shared_ptr<Shader> OpenGLRenderer::createShader() {
        return std::make_shared<OpenGLShader>();
    }

    void OpenGLRenderer::draw() {
        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
    }

    void OpenGLRenderer::clearColor(const RGBAColor& color){
        GLCall(glClearColor(color.r, color.g, color.b, color.a));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    void OpenGLRenderer::imGuiBegin() {
        imgui->begin();
    }

    void OpenGLRenderer::imGuiEnd() {
        imgui->end();
    }

    void OpenGLRenderer::begin() {

    }

    void OpenGLRenderer::end() {
        context->swapBuffers();
    }


    // CONSTRUCTORS 
    OpenGLRenderer::OpenGLRenderer() {
        MEMOGL_LOG_TRACE("Initializing OpenGL renderer...");
        context = std::make_shared<GLFWContext>();
        init();
        MEMOGL_LOG_TRACE("OpenGL {0} renderer initialized.", GLCallR(glGetString(GL_VERSION)));
    }

    OpenGLRenderer::~OpenGLRenderer() {
        MEMOGL_LOG_TRACE("OpenGL renderer has been released.");
    }
}