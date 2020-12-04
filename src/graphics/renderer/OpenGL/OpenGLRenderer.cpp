#include "OpenGLRenderer.h"
#include "tools/File.h"
#include <iostream>
#include "OpenGLError.h"
#include "graphics/context/GLFW/GLFWContext.h"




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

    IOpenGLVersion* OpenGLRenderer::getOpenGLVersion() {
        int major;
        int minor;
        glGetIntegerv(GL_MAJOR_VERSION, &major);
        glGetIntegerv(GL_MINOR_VERSION, &minor);

        if (major >= 4 && minor >= 3) {
            return new OpenGL4();
        }
        else {
            return new OpenGL3();
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
        unsigned int shader = createShaders("res/shaders/basic.vert", "res/shaders/plaincolor.frag");
        GLCall(glUseProgram(shader));
        initializeUniforms(shader);
    }

    unsigned int OpenGLRenderer::createShaders(const std::string& vertexShader, const std::string& fragmentShader) {
        GLuint program = GLCallR(glCreateProgram());
        GLuint vs = compileShader(GL_VERTEX_SHADER, readFile(vertexShader));
        GLuint fs = compileShader(GL_FRAGMENT_SHADER, readFile(fragmentShader));

        GLCall(glAttachShader(program, vs));
        GLCall(glAttachShader(program, fs));
        GLCall(glLinkProgram(program));
        GLCall(glValidateProgram(program));
        GLCall(glDeleteShader(vs));
        GLCall(glDeleteShader(fs));

        return program;
    }

    unsigned int OpenGLRenderer::compileShader(unsigned int type, const std::string& source) {
        unsigned int id = GLCallR(glCreateShader(type));
        const char* src = source.c_str();
        GLCall(glShaderSource(id, 1, &src, nullptr));
        GLCall(glCompileShader(id));

        int result;
        GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
        if (result == GL_FALSE) {
            int length;
            GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
            char* message = (char*)alloca(length * sizeof(char));
            GLCall(glGetShaderInfoLog(id, length, &length, message));

            std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " shader!" << std::endl;
            GLCall(glDeleteShader(id));
            std::cout << message << std::endl;
            return 0;
        }

        std::cout << "Succeed to compile " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " shader!" << std::endl;
        return id;
    }

    void OpenGLRenderer::initializeUniforms(unsigned int shader) {
        GLint location = GLCallR(glGetUniformLocation(shader, "u_Color"));
        ASSERT(location != -1);
        GLCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 0.1f));
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

        GLuint vertexArray;
        GLCall(glGenVertexArrays(1, &vertexArray));
        GLCall(glBindVertexArray(vertexArray));

        GLuint vertexBuffer;
        GLCall(glGenBuffers(1, &vertexBuffer));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
        GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW));

        const GLuint VERTEX_ATTR_POSITION = 0;
        GLCall(glEnableVertexAttribArray(VERTEX_ATTR_POSITION));
        GLCall(glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

        GLuint indexBuffer;
        GLCall(glGenBuffers(1, &indexBuffer));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
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
        context = new GLFWContext();
        init();
        std::cout << "OpenGL " << GLCallR(glGetString(GL_VERSION)) << " renderer initialized." << std::endl;
    }

    OpenGLRenderer::~OpenGLRenderer() {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

        if (context) {
            delete context;
            context = nullptr;
        }

        if (openGLVersion) {
            delete openGLVersion;
            openGLVersion = nullptr;
        }

        std::cout << "OpenGL renderer has been released." << std::endl;
    }
}