#pragma once
#ifndef VECTOR2_PMATH_H
#define VECTOR2_PMATH_H

#include <iostream>

namespace pmath
{
    template<typename T>
    class Vector2
    {
    public:
        Vector2();
        Vector2(T x, T y);
        Vector2(T value);
        Vector2(const Vector2<T>& vector2);
        ~Vector2();

        T Dot(const Vector2<T>& other) const;
        static T Dot(const Vector2<T>& vec1, const Vector2<T>& vec2);

        // Convenience function for returning the Z value of
        // the cross product of two (x,y,0) vectors
        T Cross(const Vector2<T>& other) const;
        static T Cross(const Vector2<T>& vec1, const Vector2<T>& vec2);

        double LengthSquared() const;
        double Length() const;

        // Normalizes the vector and returns the normalized vector
        Vector2<T> Normalize();
        // Only returns the normalized vector. Doesn't modify the original
        Vector2<T> UnitVector() const;

        #pragma region Operators
        // Comparison
        bool operator ==(const Vector2<T>& right) const;
        bool operator !=(const Vector2<T>& right) const;
        bool operator >(const Vector2<T>& right) const;
        bool operator <(const Vector2<T>& right) const;
        bool operator >=(const Vector2<T>& right) const;
        bool operator <=(const Vector2<T>& right) const;

        // Assingment
        Vector2<T>& operator =(const Vector2<T>& right);
        Vector2<T>& operator +=(const Vector2<T>& right);
        Vector2<T>& operator -=(const Vector2<T>& right);
        Vector2<T>& operator *=(const T& right);
        Vector2<T>& operator /=(const T& right);

        // Arithmetic
        Vector2<T> operator +(const Vector2<T>& right) const;
        Vector2<T> operator -() const;
        Vector2<T> operator -(const Vector2<T>& right) const;
        Vector2<T> operator *(const T& right) const;
        Vector2<T> operator /(const T& right) const;

        // Member access
        T& operator [](const unsigned int index);
        const T& operator [](const unsigned int index) const;
        #pragma endregion

        union{ T x, w; };
        union{ T y, h; };

        static const unsigned int COMPONENTS = 2;
    };

    template<typename T>
    Vector2<T> operator*(const T& left, const Vector2<T>& right);

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Vector2<T>& right);

    typedef Vector2<float>          Vec2;
    typedef Vector2<double>         Vec2d;
    typedef Vector2<int>            Vec2i;
    typedef Vector2<unsigned int>   Vec2u;
}

#include <pmath/inl/Vector2.inl>
#endif