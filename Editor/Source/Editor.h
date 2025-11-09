#pragma once

#include "System/Logger.h"
#include "System/Math/Vector.h"

#include "WSI/Window.h"

#include "GI/IRenderingFactory.h"

class Editor
{
public:
	Editor();
	~Editor();

	[[nodiscard]]
	int Run();

private:
	WSI::Window m_window;
	GI::IRenderingFactory* m_pRenderingFactory;
};