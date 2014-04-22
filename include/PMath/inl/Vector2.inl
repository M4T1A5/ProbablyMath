#include <PMath/Vector2.hpp>

namespace pmath
{
	template<typename T>
	inline Vector2<T>::Vector2()
		: x(T()),
		  y(T())
	{ }

	template<typename T>
	inline Vector2<T>::~Vector2()
	{ }
}