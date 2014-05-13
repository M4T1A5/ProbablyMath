#pragma once
#ifndef QUATERNION_PMATH_H
#define QUATERNION_PMATH_H

#include "Vector3.hpp"
#include "Vector4.hpp"

#include "Matrix3.hpp"
#include "Matrix4.hpp"

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
        explicit Quaternion(const Matrix3<T>& matrix);
        explicit Quaternion(const Matrix4<T>& matrix);
        ~Quaternion();

        static const Quaternion<T> identity;
        bool isIdentity() const;

        T dot(const Quaternion<T>& other) const;
        static T dot(const Quaternion<T>& quat1, const Quaternion<T>& quat2);

        double lengthSquared() const;
        double length() const;

        Quaternion<T> conjugate() const;

        Quaternion<T> inverse() const;

        Quaternion<T>& normalize();
        Quaternion<T> unitQuaternion() const;
        bool isUnitQuaternion() const;

        Matrix3<T> toMatrix3() const;
        Matrix4<T> toMatrix4() const;

        static Quaternion<T> createRotation(const Vector3<T>& axis, const T& angle);
        static Quaternion<T> createRotationX(const T& angle);
        static Quaternion<T> createRotationY(const T& angle);
        static Quaternion<T> createRotationZ(const T& angle);

        static Quaternion<T> slerp(const Quaternion<T>& q1, const Quaternion<T>& q2, const T& t);

        #pragma region Operators
        // Comparison
        bool operator ==(const Quaternion<T>& right) const;
        bool operator !=(const Quaternion<T>& right) const;

        // Arithmetic
        Quaternion<T> operator +(const Quaternion<T>& right) const;
        Quaternion<T> operator -(const Quaternion<T>& right) const;
        Quaternion<T> operator -() const;
        Quaternion<T> operator *(const Quaternion<T>& right) const;
        Quaternion<T> operator *(const T& right) const;
        Quaternion<T> operator /(const T& right) const;


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
    Quaternion<T> operator *(const T& left, const Quaternion<T>& right);

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

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Quaternion<T>& right);

    typedef Quaternion<float>   Quat;
    typedef Quaternion<float>   Quatf;
    typedef Quaternion<double>  Quatd;
}

#include "inl/Quaternion.inl"
#endif