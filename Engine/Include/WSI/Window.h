#pragma once

#include "System/Math/Vector.h"

#include <string>
#include <functional>

using namespace System::Math;

struct GLFWwindow;

namespace WSI
{
	using EventCallbackFn = std::function<void()>;
	using KeyCallbackFn = std::function<void(int, int, int, int)>;
	using MouseCallbackFn = std::function<void(double, double)>;
	using ResizeCallbackFn = std::function<void(int, int)>;

	class Window
	{
	public:
		Window(Vector2u size, const std::string& title);
		~Window();

		[[nodiscard]]
		bool ShouldClose() noexcept;

	private:
		GLFWwindow* m_pWindow;

		static void FramebufferSizeCallback(GLFWwindow* pWindow, int width, int height) {}
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		KeyCallbackFn m_keyCallback;
		MouseCallbackFn m_mouseCallback;
		ResizeCallbackFn m_resizeCallback;
		EventCallbackFn m_closeCallback;
	};
}