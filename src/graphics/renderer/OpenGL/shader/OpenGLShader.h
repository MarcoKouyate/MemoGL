#pragma once
#include <string>
#include <unordered_map>

namespace MemoGL {
	class OpenGLShader
	{
	public:
		OpenGLShader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
		~OpenGLShader();

		void bind() const;
		void unbind() const;

		void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

	private:
		unsigned int id;
		std::unordered_map<std::string, int> uniformLocationsCache;

		unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader);
		unsigned int compileShader(unsigned int type, const std::string& source);
		unsigned int getUniformLocation(const std::string& name);
	};
}


