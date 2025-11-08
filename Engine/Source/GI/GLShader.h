#pragma once

#include <glad/glad.h>

#include "System/IO/File.h"

namespace GI
{
	enum class ShaderType
	{
		Vertex = GL_VERTEX_SHADER,
		Pixel = GL_FRAGMENT_SHADER,
		Fragment = GL_FRAGMENT_SHADER,
	};

	class GLShader
	{
	private:
		GLuint m_shader;
		System::IO::File m_shaderFile;
		ShaderType m_type;

	public:
		GLShader(const std::string& filepath, ShaderType type);
		~GLShader();

		ShaderType GetShaderType() const noexcept { return m_type; }

		void Attach(GLuint program);
	};
}