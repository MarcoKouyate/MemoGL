#include "OpenGL33Renderer.h"
#include <iostream>
#include <string>


namespace MemoGL {

    static unsigned int CompileShader(unsigned int type, const std::string& source) {
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

    static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
        GLuint program = glCreateProgram();
        
        GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
        GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }


    void OpenGL33Renderer::init(std::shared_ptr<IWindow> pWindow) {
        window = pWindow;
        initializeGlew();

        float positions[6] = {
            -0.5f, -0.5f,
              0.0,  0.5f,
             0.5f, -0.5
        };

        GLuint buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

        const GLuint VERTEX_ATTR_POSITION = 0;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
        glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

        const std::string vs = R"glsl(
            #version 330 core

            layout(location = 0) in vec4 position;

            void main(){
               gl_Position = position;
            }
        )glsl";

        const std::string fs = R"glsl(
            #version 330 core

            layout(location = 0) out vec4 color;

            void main(){
               color = vec4(0.0, 1.0, 0.0, 1.0);
            }
        )glsl";

        unsigned int shader = CreateShader(vs, fs);
        glUseProgram(shader);

    }

    void OpenGL33Renderer::render() {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window->get());
    }


    void OpenGL33Renderer::initializeGlew() {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            window->close();
            throw std::runtime_error("Failed to initialize GLEW");
        }
    }

    OpenGL33Renderer::OpenGL33Renderer(std::shared_ptr<IWindow> pWindow) {
        std::cout << "Initializing initialized OpenGL " << glGetString(GL_VERSION) << "..." << std::endl;
        init(pWindow);
        std::cout << "OpenGL " << glGetString(GL_VERSION) << " renderer initialized." << std::endl;
    }

    OpenGL33Renderer::~OpenGL33Renderer() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        std::cout << "OpenGL 3.3 renderer has been released." << std::endl;
    }
}