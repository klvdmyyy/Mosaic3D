#include "GLPipeline.h"

#include "System/Logger.h"

using System::Logger;
using System::LogLevel;

namespace GI
{
	GLPipeline::GLPipeline(GLShader& rVertexShader, GLShader& rFragmentShader)
		: m_vertexShader(rVertexShader), m_fragmentShader(rFragmentShader)
	{
		Logger::Log(LogLevel::Info, "GI/OpenGL", "Creating a shader program.");

		m_program = glCreateProgram();

		if (rVertexShader.GetShaderType() != ShaderType::Vertex || rFragmentShader.GetShaderType() != ShaderType::Fragment)
		{
			Logger::Log(LogLevel::Critical, "GI/OpenGL", "Unexpected shader type.");
		}

		m_vertexShader.Attach(m_program);
		m_fragmentShader.Attach(m_program);

		Logger::Log(LogLevel::Info, "GI/OpenGL", "Linking a shader program.");
		glLinkProgram(m_program);

		int success;
		char infoLog[512];
		glGetProgramiv(m_program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_program, 512, NULL, infoLog);
			Logger::Log(LogLevel::Critical, "GI/OpenGL", "Failed to link GL program.\n{}", infoLog);
		}
	}

	GLPipeline::~GLPipeline()
	{
		glDeleteProgram(m_program);
	}

	void GLPipeline::Bind() const
	{
		glUseProgram(m_program);
	}
}