#include "Editor.h"

#include "WSI/Input.h"

#include <iostream>
#include <chrono>
#include <thread>

Editor::Editor() : m_window({ 800, 600 }, "Mosaic3D")
{
}

Editor::~Editor()
{
}

int Editor::Run()
{
	try
	{
		while (!m_window.ShouldClose())
		{
			WSI::Input::PollEvents();
		}
		return 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}