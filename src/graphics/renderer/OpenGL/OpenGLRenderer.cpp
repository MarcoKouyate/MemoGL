#include "OpenGLRenderer.h"
#include "OpenGLError.h"

#include "shader/OpenGLShader.h"
#include "tools/File.h"
#include "graphics/context/GLFW/GLFWContext.h"



#include <iostream>



namespace MemoGL {
    // INITIALIZATION
    void OpenGLRenderer::init() {
        initializeWindow();
        initializeGlew();
        initializeShaders();
        initializeVertexBuffers();
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

    void OpenGLRenderer::initializeShaders() {
        OpenGLShader shader("res/shaders/basic.vert", "res/shaders/plaincolor.frag");
        shader.bind();
        shader.setUniform4f("u_Color", 0.8f, 0.5f, 0.3f, 1.0f);
    }

    void OpenGLRenderer::initializeVertexBuffers() {
        float positions[] = {
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5f
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };


        vao = std::make_unique<OpenGLVertexArray>();
        vbo = std::make_shared<OpenGLVertexBuffer>(positions, 4 * 2 * sizeof(float));
        ibo = std::make_unique<OpenGLIndexBuffer>(indices, 6);

        OpenGLVertexLayout layout;
        layout.push<float>(2);
        
        vao->addBuffer(vbo, layout);

        vao->bind();
        ibo->bind();
    }







    // RENDER LOOP
    void OpenGLRenderer::render() {

        GLCall(glClear(GL_COLOR_BUFFER_BIT));
        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        context->swapBuffers();
    }




    // CONSTRUCTORS 
    OpenGLRenderer::OpenGLRenderer() {
        std::cout << "Initializing OpenGL renderer..." << std::endl;
        context = std::make_shared<GLFWContext>();
        init();
        std::cout << "OpenGL " << GLCallR(glGetString(GL_VERSION)) << " renderer initialized." << std::endl;
    }

    OpenGLRenderer::~OpenGLRenderer() {
        std::cout << "OpenGL renderer has been released." << std::endl;
    }
}