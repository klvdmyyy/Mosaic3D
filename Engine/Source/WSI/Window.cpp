#include "WSI/Window.h"
#include "System/Logger.h"

#include <GLFW/glfw3.h>

void KeyCallbackFunction(int key, int scancode, int action, int mods)
{
	std::string actionName{};
	switch (action)
	{
	case 0:
		actionName = "Pressed";
		break;
	case 1:
		actionName = "Released";
		break;
	case 2:
		actionName = "Repeating";
		break;
	default:
		actionName = std::to_string(action);
		break;
	}

	std::string modName{};
	if (mods & GLFW_MOD_CONTROL)
	{
		if (!modName.empty()) modName += "+";
		modName += "Ctrl";
	}

	if (mods & GLFW_MOD_SHIFT)
	{
		if (!modName.empty()) modName += "+";
		modName += "Shift";
	}

	if (mods & GLFW_MOD_ALT)
	{
		if (!modName.empty()) modName += "+";
		modName += "Alt";
	}

	const char* pKeyName = glfwGetKeyName(key, scancode);
	System::Logger::Log(System::LogLevel::Debug, "Input", "Key: {}; Action: {}; Mods: {}",
		pKeyName ? pKeyName : "No", actionName, modName);
}

namespace WSI
{
	Window::Window(Vector2u size, const std::string& title)
	{
		glfwInit();
		m_pWindow = glfwCreateWindow(static_cast<int>(size.x), static_cast<int>(size.y), title.c_str(), nullptr, nullptr);

		glfwSetWindowUserPointer(m_pWindow, this);

		m_keyCallback = KeyCallbackFunction;

		glfwSetKeyCallback(m_pWindow, KeyCallback);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_pWindow);
		glfwTerminate();
	}

	[[nodiscard]]
	bool Window::ShouldClose() noexcept
	{
		return glfwWindowShouldClose(m_pWindow);
	}

	void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* pWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
		if (pWindow && pWindow->m_keyCallback)
		{
			pWindow->m_keyCallback(key, scancode, action, mods);
		}
	}
}