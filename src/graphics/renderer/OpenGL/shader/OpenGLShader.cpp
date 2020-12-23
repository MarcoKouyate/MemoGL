#include "OpenGLShader.h"
#include "../OpenGLError.h"
#include "tools/File.h"
#include "tools/Log.h"

namespace MemoGL {
    OpenGLShader::OpenGLShader() :
		id(0)
	{}

    OpenGLShader::~OpenGLShader() {
        GLCall(glDeleteProgram(id));
    }

    void OpenGLShader::init(const std::string& vertexFilePath, const std::string& fragmentFilePath) {
        id = createShaders(vertexFilePath, fragmentFilePath);
    }

    unsigned int OpenGLShader::createShaders(const std::string& vertexShader, const std::string& fragmentShader) {
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

    unsigned int OpenGLShader::compileShader(unsigned int type, const std::string& source) {
        unsigned int id = GLCallR(glCreateShader(type));
        const char* src = source.c_str();
        GLCall(glShaderSource(id, 1, &src, nullptr));
        GLCall(glCompileShader(id));

        int result;
        GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
        const char* typeString = (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");

        if (result == GL_FALSE) {
            int length;
            GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
            char* message = (char*)alloca(length * sizeof(char));
            GLCall(glGetShaderInfoLog(id, length, &length, message));



            MEMOGL_LOG_ERROR("Failed to compile {0} shader!", typeString);
            GLCall(glDeleteShader(id));
            MEMOGL_LOG_ERROR(message);
            return 0;
        }

        MEMOGL_LOG_TRACE("Succeed to compile {0} shader!", typeString);
        return id;
    }

    void OpenGLShader::bind() const {
        GLCall(glUseProgram(id));
    }

    void OpenGLShader::unbind() const {
        GLCall(glUseProgram(0));
    }

    void OpenGLShader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
        GLCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
    }

    void OpenGLShader::setUniform1i(const std::string& name, int value) {
        GLCall(glUniform1i(getUniformLocation(name), value));
    }

    void OpenGLShader::setUniform1f(const std::string& name, float value) {
        GLCall(glUniform1f(getUniformLocation(name), value));
    }

    void OpenGLShader::setUniformMat4f(const std::string& name, const glm::mat4& matrix) {
        GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
    }

    int OpenGLShader::getUniformLocation(const std::string& name) {

        if (uniformLocationsCache.find(name) != uniformLocationsCache.end()) {
            return uniformLocationsCache[name];
        }

        int location = GLCallR(glGetUniformLocation(id, name.c_str()));

        if (location == -1) {
            MEMOGL_LOG_WARNING("uniform {0} doesn't exist.", name);
        }

        uniformLocationsCache[name] = location;
        return location;
    }
}