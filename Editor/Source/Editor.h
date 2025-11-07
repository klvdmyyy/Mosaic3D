#pragma once

#include "System/Logger.h"
#include "WSI/Window.h"

class Editor
{
public:
	Editor();
	~Editor();

	[[nodiscard]]
	int Run();

private:
	WSI::Window m_window;
};