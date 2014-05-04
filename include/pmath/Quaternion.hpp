#pragma once
#ifndef QUATERNION_PMATH_H
#define QUATERNION_PMATH_H

#include <pmath/Vector3.hpp>
#include <pmath/Vector4.hpp>

#include <iostream>

namespace pmath
{
    template<typename T>
    class Quaternion
    {
    public:
        Quaternion();
        Quaternion(T w, T x, T y, T z);
        Quaternion(T w, Vector3<T> vector);
        Quaternion(const Quaternion<T>& quaternion);
        template<typename T2>
        Quaternion(const Quaternion<T2>& quaternion);
        ~Quaternion();

        static const Quaternion<T> identity;
        bool isIdentity() const;
        T w;
        Vector3<T> vector;

        #pragma region Operators
        // Comparison
        bool operator ==(const Quaternion<T>& right);
        bool operator !=(const Quaternion<T>& right);

        // Arithmetic
        Quaternion<T> operator +(const Quaternion<T>& right);
        Quaternion<T> operator -(const Quaternion<T>& right);

        // Assingment
        Quaternion<T>& operator =(const Quaternion<T>& right);
        Quaternion<T>& operator +=(const Quaternion<T>& right);

        #pragma endregion
    };

    typedef Quaternion<float>   quat;
    typedef Quaternion<float>   quatf;
    typedef Quaternion<double>  quatd;
}

#include <pmath/inl/Quaternion.inl>
#endif