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
        Quaternion(const T& w, const T& x, const T& y, const T& z);
        Quaternion(const T& w, const Vector3<T>& vector);
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

    template<typename T>
    Vector3<T> operator *(const Vector3<T>& left, const Quaternion<T>& right);
    template<typename T>
    Vector3<T> operator *(const Quaternion<T>& left, const Vector3<T>& right);

    template<typename T>
    // Treats the vector as homogeneous e.g. (x,y,z,1)
    Vector4<T> operator *(const Vector4<T>& left, const Quaternion<T>& right);
    template<typename T>
    Vector4<T> operator *(const Quaternion<T>& left, const Vector4<T>& right);

    template<typename T>
    Vector3<T>& operator *=(Vector3<T>& left, const Quaternion<T>& right);
    template<typename T>
    Vector4<T>& operator *=(Vector4<T>& left, const Quaternion<T>& right);


    typedef Quaternion<float>   Quat;
    typedef Quaternion<float>   Quatf;
    typedef Quaternion<double>  Quatd;
}

#include <pmath/inl/Quaternion.inl>
#endif