#include "GLRenderingFactory.h"

#include "System/Logger.h"

namespace GI
{
	GLRenderingFactory::GLRenderingFactory()
	{
		System::Logger::Log(System::LogLevel::Info, "GI/OpenGL", "Initializing OpenGL rendering factory.");
	}

	GLRenderingFactory::~GLRenderingFactory()
	{
		System::Logger::Log(System::LogLevel::Info, "GI/OpenGL", "Destroying OpenGL rendering factory.");
	}
}