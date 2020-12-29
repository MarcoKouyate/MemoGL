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
        openGLVersion = std::make_unique<OpenGL4>();
    }


    void OpenGLRenderer::initializeGlew() {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
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


    // CONSTRUCTORS 
    OpenGLRenderer::OpenGLRenderer(const IContext& context) : context(context) {
        MEMOGL_LOG_TRACE("Initializing OpenGL renderer...");
        init();
        MEMOGL_LOG_TRACE("OpenGL {0} renderer initialized.", GLCallR(glGetString(GL_VERSION)));
    }

    OpenGLRenderer::~OpenGLRenderer() {
        MEMOGL_LOG_TRACE("OpenGL renderer has been released.");
    }
}