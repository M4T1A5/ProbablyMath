#pragma once
#ifndef VECTOR_PMATH_H
#define VECTOR_PMATH_H

namespace pmath
{
	template<typename T>
	class Vector2
	{
	public:
		Vector2();
		~Vector2();

		union
		{
			struct {T x, y;};
			struct {T w, h;};
		};
		//union{T y, h};
	};

	typedef Vector2<float>	Vec2;
	typedef Vector2<double>	Vec2d;
	typedef Vector2<int>	Vec2i;
}

#include <PMath/inl/Vector2.inl>
#endif