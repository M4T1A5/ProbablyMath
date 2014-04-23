#pragma once
#ifndef VECTOR3_PMATH_H
#define VECTOR3_PMATH_H

#include <iostream>

namespace pmath
{
	template<typename T>
	class Vector3
	{
	public:
		Vector3();
		Vector3(T x, T y, T z);
		Vector3(T value);
		Vector3(const Vector3<T>& vector3);
		~Vector3();

		const T Dot(const Vector3<T>& other) const;
		static const T Dot(const Vector3<T>& vec1, const Vector3<T>& vec2);

        const Vector3<T> Cross(const Vector3<T>& other) const;
        static const Vector3<T> Cross(const Vector3<T>& vec1, const Vector3<T>& vec2);

		const T LengthSquared() const;
		const T Length() const;

#pragma region Operators
		Vector3<T>& operator=(const Vector3<T>& right);

		bool operator ==(const Vector3<T>& right) const;
		bool operator !=(const Vector3<T>& right) const;

		Vector3<T>& operator +=(const Vector3<T>& right);
		Vector3<T>& operator -=(const Vector3<T>& right);
		Vector3<T>& operator *=(const T& right);
		Vector3<T>& operator /=(const T& right);

		Vector3<T> operator +(const Vector3<T>& right) const;
		Vector3<T> operator -() const;
		Vector3<T> operator -(const Vector3<T>& right) const;
		Vector3<T> operator *(const T& right) const;
		Vector3<T> operator /(const T& right) const;
#pragma endregion

		union{ T x, r; };
		union{ T y, g; };
		union{ T z, b; };
	};

	template<typename T>
	Vector3<T> operator*(const T& left, const Vector3<T>& right);

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Vector3<T>& right);

	typedef Vector3<float>			Vec3;
	typedef Vector3<double>			Vec3d;
	typedef Vector3<int>			Vec3i;
	typedef Vector3<unsigned int>	Vec3u;
}

#include <pmath/inl/Vector3.inl>
#endif