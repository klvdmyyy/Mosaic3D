#pragma once

#include "System/Math/Vector.h"

#include <string>

using namespace System::Math;

struct GLFWwindow;

namespace GI
{
	class RenderingWindow
	{
	public:
		RenderingWindow(Vector2u size, const std::string& title);
		~RenderingWindow();

		[[nodiscard]]
		bool ShouldClose();

	private:
		GLFWwindow* mpWindow;
	};
}