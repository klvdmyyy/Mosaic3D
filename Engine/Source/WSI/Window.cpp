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
	System::Logger::Log(System::LogLevel::Debug, "WSI/Input", "Key: {}; Action: {}; Mods: {}",
		pKeyName ? pKeyName : "NN", actionName, modName);
}

namespace WSI
{
	Window::Window(Vector2u size, const std::string& title)
	{
		System::Logger::Log(System::LogLevel::Info, "WSI/Window", "Initializing WSI...");
		if (glfwInit() == GLFW_FALSE)
		{
			System::Logger::Log(System::LogLevel::Critical, "WSI/Window", "Failed to initialize GLFW.");
		}

		// TODO: glfwSetErrorCallback

		System::Logger::Log(System::LogLevel::Info, "WSI/Window", "Creating window...");
		m_pWindow = glfwCreateWindow(static_cast<int>(size.x), static_cast<int>(size.y), title.c_str(), nullptr, nullptr);
		if (!m_pWindow)
		{
			System::Logger::Log(System::LogLevel::Critical, "WSI/Window", "Failed to create window '{}'", title);
		}

		glfwSetWindowUserPointer(m_pWindow, this);

		m_keyCallback = KeyCallbackFunction;

		glfwSetKeyCallback(m_pWindow, KeyCallback);
	}

	Window::~Window()
	{
		System::Logger::Log(System::LogLevel::Info, "WSI/Window", "Terminating WSI and all windows");
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