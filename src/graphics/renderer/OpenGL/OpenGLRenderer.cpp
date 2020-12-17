#include "OpenGLRenderer.h"
#include "OpenGLError.h"

#include "tools/File.h"
#include "graphics/context/GLFW/GLFWContext.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>



namespace MemoGL {
    // INITIALIZATION
    void OpenGLRenderer::init() {
        initializeWindow();
        initializeGlew();
        initializeShaders();
        initializeTextures();
        initializeVertexBuffers();
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

    void OpenGLRenderer::initializeShaders() {
        proj = glm::ortho(-2.0f, 2.0f, -1.125f, 1.125f, -1.0f, 1.0f);
        view = glm::translate(glm::mat4(1.0f), glm::vec3(camera_position_x, camera_position_y, 0));
        model = glm::translate(glm::mat4(1.0f), translationA);

        glm::mat4 mvp = proj * view * model;


        shader = std::make_unique<OpenGLShader>("res/shaders/texture2d.vert", "res/shaders/texture2d.frag");
        shader->bind();
        shader->setUniform4f("u_Color", 0.8f, 0.5f, 0.3f, 1.0f);
        shader->setUniformMat4f("u_MVP", mvp);
        shader->setUniform1i("u_Texture_Slot", 0);
    }

    void OpenGLRenderer::initializeTextures() {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        
        texture = std::make_unique<OpenGLTexture>("res/textures/memoticone_admiration.png");
        texture->bind();
    }

    void OpenGLRenderer::initializeVertexBuffers() {
        float positions[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,
             0.5f, -0.5f, 1.0f, 0.0f,
             0.5f,  0.5f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 1.0f
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        vao = std::make_unique<OpenGLVertexArray>();
        vbo = std::make_shared<OpenGLVertexBuffer>(positions, 4 * 4 * sizeof(float));
        ibo = std::make_unique<OpenGLIndexBuffer>(indices, 6);

        OpenGLVertexLayout layout;
        layout.push<float>(2);
        layout.push<float>(2);
        
        vao->addBuffer(vbo, layout);

        vao->bind();
        ibo->bind();
    }


    void OpenGLRenderer::initializeImGui() {
        imgui = std::make_unique<OpenGLImGui>(context, "#version 330", true);
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
        std::cout << "Initializing OpenGL renderer..." << std::endl;
        context = std::make_shared<GLFWContext>();
        init();
        std::cout << "OpenGL " << GLCallR(glGetString(GL_VERSION)) << " renderer initialized." << std::endl;
    }

    OpenGLRenderer::~OpenGLRenderer() {
        std::cout << "OpenGL renderer has been released." << std::endl;
    }
}