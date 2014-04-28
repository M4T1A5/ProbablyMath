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
        Vector4(const Vector4<T>& vector);
        template<typename T2>
        Vector4(const Vector4<T2>& vector);
        ~Vector4();

        T dot(const Vector4<T>& other) const;
        static T dot(const Vector4<T>& vec1, const Vector4<T>& vec2);

        double lengthSquared() const;
        double length() const;

        static double distance(const Vector4<T>& vec1, const Vector4<T>& vec2);

        // Normalizes the vector and returns the normalized vector
        Vector4<T> normalize();
        // Only returns the normalized vector. Doesn't modify the original
        Vector4<T> unitVector() const;

        #pragma region Operators
        // Comparison
        bool operator ==(const Vector4<T>& right) const;
        bool operator !=(const Vector4<T>& right) const;
        bool operator >(const Vector4<T>& right) const;
        bool operator <(const Vector4<T>& right) const;
        bool operator >=(const Vector4<T>& right) const;
        bool operator <=(const Vector4<T>& right) const;

        // Assingment
        template<typename T2>
        Vector4<T>& operator =(const Vector4<T2>& right);
        template<typename T2>
        Vector4<T>& operator +=(const Vector4<T2>& right);
        template<typename T2>
        Vector4<T>& operator -=(const Vector4<T2>& right);
        template<typename T2>
        Vector4<T>& operator *=(const T2& right);
        template<typename T2>
        Vector4<T>& operator /=(const T2& right);

        // Arithmetic
        Vector4<T> operator +(const Vector4<T>& right) const;
        Vector4<T> operator -() const;
        Vector4<T> operator -(const Vector4<T>& right) const;
        Vector4<T> operator *(const T& right) const;
        Vector4<T> operator /(const T& right) const;

        // Member access
        T& operator [](const unsigned int index);
        const T& operator [](const unsigned int index) const;
        #pragma endregion

        union{ T x, r; };
        union{ T y, g; };
        union{ T z, b; };
        union{ T w, a; };

        static const unsigned int COMPONENTS = 4;
    };

    template<typename T>
    Vector4<T> operator*(const T& left, const Vector4<T>& right);

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Vector4<T>& right);

    typedef Vector4<float>          Vec4;
    typedef Vector4<double>         Vec4d;
    typedef Vector4<int>            Vec4i;
    typedef Vector4<unsigned int>   Vec4u;
}

#include <pmath/inl/Vector4.inl>
#endif