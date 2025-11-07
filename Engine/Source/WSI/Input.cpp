#include "WSI/Input.h"

#include <GLFW/glfw3.h>

namespace WSI
{
	void Input::PollEvents()
	{
		glfwPollEvents();
	}
}