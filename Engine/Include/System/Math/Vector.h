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
		using Vector2f = Vector<float, 2>;

		template<class T>
		class Vector<T, 3>
		{
		public:
			T x, y, z;

			Vector(T value) : x(value), y(value), z(value) {}
			Vector(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}
		};

		using Vector3u = Vector<unsigned int, 3>;
		using Vector3i = Vector<int, 3>;
		using Vector3f = Vector<float, 3>;
	}
}