#pragma once

#include "GI/IMeshRenderer.h"
#include "GI/ISpriteRenderer.h"

namespace GI
{
	enum class Backend
	{
		OpenGL,
	};
	class IRenderingFactory
	{
	public:

		static IRenderingFactory* Create(Backend);

		virtual ~IRenderingFactory() = default;

		virtual IMeshRenderer* GetMeshRenderer() = 0;
		virtual ISpriteRenderer* GetSpriteRenderer() = 0;
	};
}
