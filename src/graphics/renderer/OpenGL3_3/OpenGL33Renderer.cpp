#include "OpenGL33Renderer.h"
#include "tools/File.h"
#include <iostream>
#include "OpenGL33Error.h"


namespace MemoGL {
    // INITIALIZATION
    void OpenGL33Renderer::init(std::shared_ptr<IWindow> pWindow) {
        window = pWindow;
        initializeGlew();
        initializeShaders();
        initializeVertexBuffers();
    }

    void OpenGL33Renderer::initializeGlew() {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            window->close();
            throw std::runtime_error("Failed to initialize GLEW");
        }
    }

    void OpenGL33Renderer::initializeShaders() {
        const std::string vs = readFile("res/shaders/basic.vert");
        const std::string fs = readFile("res/shaders/green.frag");
        unsigned int shader = createShaders(vs, fs);
        glUseProgram(shader);
    }

    void OpenGL33Renderer::initializeVertexBuffers() {
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
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

        const GLuint VERTEX_ATTR_POSITION = 0;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
        glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

        GLuint indexBuffer;
        glGenBuffers(1, &indexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    }

    unsigned int OpenGL33Renderer::createShaders(const std::string& vertexShader, const std::string& fragmentShader) {
        GLuint program = glCreateProgram();
        GLuint vs = compileShader(GL_VERTEX_SHADER, vertexShader);
        GLuint fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);
        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    unsigned int OpenGL33Renderer::compileShader(unsigned int type, const std::string& source) {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);

            std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " shader!" << std::endl;
            glDeleteShader(id);
            std::cout << message << std::endl;
            return 0;
        }

        std::cout << "Succeed to compile " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " shader!" << std::endl;
        return id;
    }





    // RENDER LOOP
    void OpenGL33Renderer::render() {
        glClear(GL_COLOR_BUFFER_BIT);
        CallGL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        glfwSwapBuffers(window->get());
    }



    // CONSTRUCTORS 
    OpenGL33Renderer::OpenGL33Renderer(std::shared_ptr<IWindow> pWindow) {
        std::cout << "Initializing initialized OpenGL " << glGetString(GL_VERSION) << "..." << std::endl;
        init(pWindow);
        std::cout << "OpenGL " << glGetString(GL_VERSION) << " renderer initialized." << std::endl;
    }

    OpenGL33Renderer::~OpenGL33Renderer() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        std::cout << "OpenGL 3.3 renderer has been released." << std::endl;
    }
}