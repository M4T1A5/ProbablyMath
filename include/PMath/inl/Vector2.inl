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

#pragma region Operators
	// Assingment operators
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator=(const Vector2<T>& right)
	{
		this.x = right.x;
		this.y = right.y;

		return *this;
	}

	template<typename T>
	inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& right)
	{
		this->x += right.x;
		this->y += right.y;

		return *this;
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& right)
	{
		this->x -= right.x;
		this->y -= right.y;

		return *this;
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator*=(const T right)
	{
		this->x *= right;
		this->y *= right;

		return *this;
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator/=(const T right)
	{
		this->x /= right;
		this->y /= right;

		return *this;
	}


	// Arithmetic operators
	template<typename T>
	inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& right)
	{
		Vector2<T> out = *this;
		out.x += right.x;
		out.y += right.y;

		return out;
	}
	template<typename T>
	inline Vector2<T> Vector2<T>::operator-()
	{
		Vector2<T> out = *this;
		out.x = -out.x;
		out.y = -out.y;

		return out;
	}
	template<typename T>
	inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& right)
	{
		Vector2<T> out = *this;
		out.x -= right.x;
		out.y -= right.y;

		return out;
	}	
	template<typename T>
	inline Vector2<T> Vector2<T>::operator*(const T right)
	{
		Vector2<T> out = *this;
		out.x *= right;
		out.y *= right;

		return out;
	}
	template<typename T>
	inline Vector2<T> Vector2<T>::operator/(const T right)
	{
		Vector2<T> out = *this;
		out.x /= right;
		out.y /= right;

		return out;
	}
#pragma endregion
}