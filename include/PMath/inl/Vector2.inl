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
	inline Vector2<T>::Vector2(const Vector2<T>& vector2)
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
		x = right.x;
		y = right.y;

		return *this;
	}

	template<typename T>
	inline bool Vector2<T>::operator==(const Vector2<T>& right) const
	{
		return x == right.x && y == right.y;
	}
	template<typename T>
	inline bool Vector2<T>::operator!=(const Vector2<T>& right) const
	{
		return x != right.x || y != right.y;
	}

	template<typename T>
	inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& right)
	{
		x += right.x;
		y += right.y;

		return *this;
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& right)
	{
		x -= right.x;
		y -= right.y;

		return *this;
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator*=(const T& right)
	{
		x *= right;
		y *= right;

		return *this;
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator/=(const T& right)
	{
		x /= right;
		y /= right;

		return *this;
	}


	// Arithmetic operators
	template<typename T>
	inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& right) const
	{
		return Vector2<T>(x + right.x, y + right.y);
	}
	template<typename T>
	inline Vector2<T> Vector2<T>::operator-() const
	{
		return Vector2<T>(-x, -y);
	}
	template<typename T>
	inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& right) const
	{
		return Vector2<T>(x - right.x, y - right.y);
	}	
	template<typename T>
	inline Vector2<T> Vector2<T>::operator*(const T& right) const
	{
		return Vector2<T>(x * right, y * right);
	}
	template<typename T>
	inline Vector2<T> Vector2<T>::operator/(const T& right) const
	{
		return Vector2<T>(x / right, y / right);
	}

	template<typename T>
	inline Vector2<T> operator*(const T& left, const Vector2<T>& right)
	{
		return right * left;
	}
	
	template<typename T>
	inline std::ostream& operator<<(std::ostream& out, const Vector2<T>& right)
	{
		out << "X: " << right.x << " Y: " << right.y;

		return out;
	}
#pragma endregion
}