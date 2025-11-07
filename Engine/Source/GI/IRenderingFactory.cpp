#include "GI/IRenderingFactory.h"
#include "GLRenderingFactory.h"

#include "System/Logger.h"

namespace GI
{
	IRenderingFactory* IRenderingFactory::Create(Backend b)
	{
		switch (b)
		{
		case Backend::OpenGL:
			return new GLRenderingFactory();

		default:
			System::Logger::Log(System::LogLevel::Critical, "GI", "Failed to create rendering factory. Unknown or unsupported backend value provided.");
		}
	}
}