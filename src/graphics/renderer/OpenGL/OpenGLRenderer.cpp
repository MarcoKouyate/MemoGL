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
        initializeUniforms();
        initializeVertexBuffers();
        openGLVersion->initErrorCalls(); 
    }

    void OpenGLRenderer::initializeWindow() {
        ContextSettings properties;
        properties.window = WindowSettings(1280, 720, "MemoGL");
        openGLVersion->changeSettings(properties);
        context->init(properties);
    }


    void OpenGLRenderer::initializeGlew() {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            context->close();
            throw std::runtime_error("Failed to initialize GLEW");
        }
    }

    void OpenGLRenderer::initializeShaders() {
        const std::string vs = readFile("res/shaders/basic.vert");
        const std::string fs = readFile("res/shaders/green.frag");
        unsigned int shader = createShaders(vs, fs);
        GLCall(glUseProgram(shader));
    }

    void OpenGLRenderer::initializeUniforms() {

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
    }

    unsigned int OpenGLRenderer::createShaders(const std::string& vertexShader, const std::string& fragmentShader) {
        GLuint program = GLCallR(glCreateProgram());
        GLuint vs = compileShader(GL_VERTEX_SHADER, vertexShader);
        GLuint fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

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
        openGLVersion = new OpenGL4();
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