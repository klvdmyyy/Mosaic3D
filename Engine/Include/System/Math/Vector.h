#pragma once

namespace System
{
	namespace Math
	{
		template<class T, unsigned int L>
		class Vector;

		template<class T>
		class Vector<T, 2>
		{
		public:
			T x, y;
		};

		using Vector2u = Vector<unsigned int, 2>;
	}
}