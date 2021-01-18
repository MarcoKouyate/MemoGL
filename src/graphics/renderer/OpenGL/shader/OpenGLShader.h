#pragma once
#include "glm/glm.hpp"
#include "graphics/buffer/Shader.h"

namespace MemoGL {
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader();
		~OpenGLShader() override;

		void init(const std::string& vertexFilePath, const std::string& fragmentFilePath) override;

		void bind() const override;
		void unbind() const override;

		void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) override;
		void setUniform1i(const std::string& name, int value) override;
		void setUniform1f(const std::string& name, float value) override;
		void setUniformMat4f(const std::string& name, const glm::mat4& matrix) override;

	private:
		unsigned int id;
		std::unordered_map<std::string, int> uniformLocationsCache;

		unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader);
		unsigned int compileShader(unsigned int type, const std::string& source);
		int getUniformLocation(const std::string& name);
	};
}


