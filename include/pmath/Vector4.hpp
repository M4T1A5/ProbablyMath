#pragma once
#ifndef VECTOR4_PMATH_H
#define VECTOR4_PMATH_H

#include <iostream>

namespace pmath
{
	template<typename T>
	class Vector4
	{
	public:
		Vector4();
		Vector4(T x, T y, T z, T w);
		Vector4(T value);
		Vector4(const Vector4<T>& vector4);
		~Vector4();

		const T Dot(const Vector4<T>& other) const;
		static const T Dot(const Vector4<T>& vec1, const Vector4<T>& vec2);

		const T LengthSquared() const;
		const T Length() const;

#pragma region Operators
		Vector4<T>& operator=(const Vector4<T>& right);

		bool operator ==(const Vector4<T>& right) const;
		bool operator !=(const Vector4<T>& right) const;

		Vector4<T>& operator +=(const Vector4<T>& right);
		Vector4<T>& operator -=(const Vector4<T>& right);
		Vector4<T>& operator *=(const T& right);
		Vector4<T>& operator /=(const T& right);

		Vector4<T> operator +(const Vector4<T>& right) const;
		Vector4<T> operator -() const;
		Vector4<T> operator -(const Vector4<T>& right) const;
		Vector4<T> operator *(const T& right) const;
		Vector4<T> operator /(const T& right) const;
#pragma endregion

		union{ T x, r; };
		union{ T y, g; };
		union{ T z, b; };
		union{ T w, a; };
	};

	template<typename T>
	Vector4<T> operator*(const T& left, const Vector4<T>& right);

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Vector4<T>& right);

	typedef Vector4<float>			Vec4;
	typedef Vector4<double>			Vec4d;
	typedef Vector4<int>			Vec4i;
	typedef Vector4<unsigned int>	Vec4u;
}

#include <pmath/inl/Vector4.inl>
#endif