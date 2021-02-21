#include "OpenGLRenderer.h"

// buffers
#include "graphics/context/GLFW/WindowGLFW.h"
#include "graphics/buffer/Vertex2D.h"
#include "buffer/OpenGLIndexBuffer.h"
#include "buffer/OpenGLVertexArray.h"

#include "shader/OpenGLShader.h"

//tools
#include "OpenGLError.h"
#include "tools/Log.h"
#include "tools/File.h"
#include "glm/glm.hpp"

// version
#include "versions/OpenGL3.h"
#include "versions/OpenGL4.h"


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

    std::shared_ptr<OpenGLTexture> OpenGLRenderer::createTexture() {
        return std::make_shared<OpenGLTexture>();
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
    OpenGLRenderer::OpenGLRenderer(const IWindow& context) : context(context) {
        MEMOGL_LOG_TRACE("Initializing OpenGL renderer...");
        init();
        MEMOGL_LOG_TRACE("OpenGL {0} renderer initialized.", GLCallR(glGetString(GL_VERSION)));
    }

    OpenGLRenderer::~OpenGLRenderer() {
        MEMOGL_LOG_TRACE("OpenGL renderer has been released.");
    }
}