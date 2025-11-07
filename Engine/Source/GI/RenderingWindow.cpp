#include "GI/RenderingWindow.h"

#include <GLFW/glfw3.h>

namespace GI
{
	RenderingWindow::RenderingWindow(Vector2u size, const std::string& title)
	{
		glfwInit();
		mpWindow = glfwCreateWindow(static_cast<int>(size.x), static_cast<int>(size.y), title.c_str(), nullptr, nullptr);
	}

	RenderingWindow::~RenderingWindow()
	{
		glfwDestroyWindow(mpWindow);
		glfwTerminate();
	}

	[[nodiscard]]
	bool RenderingWindow::ShouldClose()
	{
		return glfwWindowShouldClose(mpWindow);
	}
}