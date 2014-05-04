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

        double lengthSquared() const;
        double length() const;

        Quaternion<T> conjugate() const;

        Quaternion<T> inverse() const;

        Quaternion<T>& normalize();
        Quaternion<T> unitQuaternion() const;
        bool isUnitQuaternion() const;

        #pragma region Operators
        // Comparison
        bool operator ==(const Quaternion<T>& right);
        bool operator !=(const Quaternion<T>& right);

        // Arithmetic
        Quaternion<T> operator +(const Quaternion<T>& right);
        Quaternion<T> operator -(const Quaternion<T>& right);
        Quaternion<T> operator -();
        Quaternion<T> operator *(const Quaternion<T>& right);
        Quaternion<T> operator *(const T& right);
        Quaternion<T> operator /(const T& right);


        // Assingment
        Quaternion<T>& operator =(const Quaternion<T>& right);
        Quaternion<T>& operator +=(const Quaternion<T>& right);
        Quaternion<T>& operator -=(const Quaternion<T>& right);
        Quaternion<T>& operator *=(const Quaternion<T>& right);
        Quaternion<T>& operator *=(const T& right);
        Quaternion<T>& operator /=(const T& right);
        #pragma endregion

        T w;
        Vector3<T> vector;
    };

    //template<typename T>
    //Vector3<T>& operator *=(Vector3<T>& left, const Quaternion<T>& right);
    //template<typename T>
    //Vector4<T>& operator *=(Vector4<T>& left, const Quaternion<T>& right);


    typedef Quaternion<float>   quat;
    typedef Quaternion<float>   quatf;
    typedef Quaternion<double>  quatd;
}

#include <pmath/inl/Quaternion.inl>
#endif