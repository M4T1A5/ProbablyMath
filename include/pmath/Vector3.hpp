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
        explicit Vector3(T value);
        Vector3(const Vector3<T>& vector);
        template<typename T2>
        Vector3(const Vector3<T2>& vector);
        ~Vector3();

        T dot(const Vector3<T>& other) const;
        static T dot(const Vector3<T>& vec1, const Vector3<T>& vec2);

        Vector3<T> cross(const Vector3<T>& other) const;
        static Vector3<T> cross(const Vector3<T>& vec1, const Vector3<T>& vec2);

        double lengthSquared() const;
        double length() const;

        static double distance(const Vector3<T>& vec1, const Vector3<T>& vec2);

        // Normalizes the vector and returns the normalized vector
        Vector3<T> normalize();
        // Only returns the normalized vector. Doesn't modify the original
        Vector3<T> unitVector() const;

        #pragma region Operators
        // Comparison
        bool operator ==(const Vector3<T>& right) const;
        bool operator !=(const Vector3<T>& right) const;
        bool operator >(const Vector3<T>& right) const;
        bool operator <(const Vector3<T>& right) const;
        bool operator >=(const Vector3<T>& right) const;
        bool operator <=(const Vector3<T>& right) const;

        // Assingment
        Vector3<T>& operator =(const Vector3<T>& right);
        Vector3<T>& operator +=(const Vector3<T>& right);
        Vector3<T>& operator -=(const Vector3<T>& right);
        Vector3<T>& operator *=(const T& right);
        Vector3<T>& operator /=(const T& right);

        // Arithmetic
        Vector3<T> operator +(const Vector3<T>& right) const;
        Vector3<T> operator -() const;
        Vector3<T> operator -(const Vector3<T>& right) const;
        Vector3<T> operator *(const T& right) const;
        Vector3<T> operator /(const T& right) const;

        // Member access
        T& operator [](const unsigned int index);
        const T& operator [](const unsigned int index) const;
        #pragma endregion

        union{ T x, r; };
        union{ T y, g; };
        union{ T z, b; };

        static const unsigned int COMPONENTS = 3;
    };

    template<typename T>
    Vector3<T> operator*(const T& left, const Vector3<T>& right);

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Vector3<T>& right);

    typedef Vector3<float>          Vec3;
    typedef Vector3<double>         Vec3d;
    typedef Vector3<int>            Vec3i;
    typedef Vector3<unsigned int>   Vec3u;
}

#include <pmath/inl/Vector3.inl>
#endif