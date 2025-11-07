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

			Vector(T value) : x(value), y(value) {}
			Vector(T x_, T y_) : x(x_), y(y_) {}
		};

		using Vector2u = Vector<unsigned int, 2>;
		using Vector2i = Vector<int, 2>;
		using Vector2f = Vector<float, 2> ;
	}
}