#pragma once

#include <glad/glad.h>

#include "GLShader.h"

#include "GI/IPipeline.h"

namespace GI
{
	class GLPipeline : public IPipeline
	{
	private:
		GLShader& m_vertexShader;
		GLShader& m_fragmentShader;

		GLuint m_program;

	public:
		GLPipeline(GLShader& rVertexShader, GLShader& rFragmentShader);
		~GLPipeline();

		void Bind() const;
	};
}