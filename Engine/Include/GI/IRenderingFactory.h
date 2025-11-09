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
		[[nodiscard]]
		static IRenderingFactory* Create(Backend);

		virtual ~IRenderingFactory() = default;
	};
}
