#include "Editor.h"

#include "WSI/Input.h"

#include <iostream>
#include <chrono>
#include <thread>

Editor::Editor() : m_window({ 800, 600 }, "Mosaic3D")
{
	m_pRenderingFactory = GI::IRenderingFactory::Create(GI::Backend::OpenGL);
}

Editor::~Editor()
{
	delete m_pRenderingFactory;
}

int Editor::Run()
{
	std::vector<System::Vertex> vertices{
		{{0.5f, -0.5f, 0.0f}},
		{{0.0f, 0.5f, 0.0f}},
		{{-0.5f, -0.5f, 0.0f}},
	};
	System::Mesh triangle{ vertices, {}, {} };
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