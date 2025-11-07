#include "Editor.h"

#include "WSI/Input.h"

#include <iostream>
#include <chrono>
#include <thread>

Editor::Editor() : m_window({ 800, 600 }, "Mosaic3D")
{
	m_pRenderingFactory = GI::IRenderingFactory::Create(GI::Backend::OpenGL);

	m_pSpriteRenderer = m_pRenderingFactory->GetSpriteRenderer();
}

Editor::~Editor()
{
	delete m_pRenderingFactory;
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