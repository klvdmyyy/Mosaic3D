#pragma once

#include "System/Logger.h"
#include "GI/RenderingWindow.h"

class Editor
{
public:
	Editor();
	~Editor();

	[[nodiscard]]
	int Run();

private:
	GI::RenderingWindow mWindow;
};