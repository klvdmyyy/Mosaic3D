#include "GLShader.h"

#include "System/Logger.h"

using System::Logger;
using System::LogLevel;

namespace GI
{
	GLShader::GLShader(const std::string& filepath, ShaderType type)
		: m_shaderFile(filepath), m_type(type)
	{
		m_shader = glCreateShader((GLuint)type);

		int success;
		char infoLog[512];

		auto shaderCode = m_shaderFile.ReadBytes();

		std::vector<const char*> shaders
		{
			shaderCode.data(),
		};

		std::vector<GLint> shaderSizes
		{
			static_cast<GLint>(shaderCode.size()),
		};

		Logger::Log(LogLevel::Info, "GI/OpenGL", "Compiling shader: {}", filepath);

		glShaderSource(m_shader, 1, shaders.data(), shaderSizes.data());
		glCompileShader(m_shader);

		glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(m_shader, 512, nullptr, infoLog);
			Logger::Log(LogLevel::Critical, "GI/OpenGL", "Failed to compile shader: {}. Error: {}", filepath, infoLog);
		}
	}

	GLShader::~GLShader()
	{
		glDeleteShader(m_shader);
	}

	void GLShader::Attach(GLuint program)
	{
		glAttachShader(program, m_shader);
	}
}