#include <PMath/Vector2.hpp>

namespace pmath
{
	template<typename T>
	inline Vector2<T>::Vector2()
		: x(T()),
		  y(T())
	{ }

	template<typename T>
	inline Vector2<T>::Vector2(T x, T y)
		: x(x),
		  y(y)
	{ }


	template<typename T>
	Vector2<T>::Vector2(const Vector2<T>& vector2)
		: x(vector2.x),
		  y(vector2.y)
	{ }

	template<typename T>
	inline Vector2<T>::~Vector2()
	{ }
}