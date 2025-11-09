#pragma once

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
	};
}
