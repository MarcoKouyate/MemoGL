#pragma once
#include <string>
#include <unordered_map>
#include "glm/glm.hpp"

namespace MemoGL {
	class OpenGLShader
	{
	public:
		OpenGLShader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
		~OpenGLShader();

		void bind() const;
		void unbind() const;

		void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void setUniform1i(const std::string& name, int value);
		void setUniform1f(const std::string& name, float value);
		void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

	private:
		unsigned int id;
		std::unordered_map<std::string, int> uniformLocationsCache;

		unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader);
		unsigned int compileShader(unsigned int type, const std::string& source);
		int getUniformLocation(const std::string& name);
	};
}


