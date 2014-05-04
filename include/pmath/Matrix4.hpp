#pragma once
#ifndef MATRIX4_PMATH_H
#define MATRIX4_PMATH_H

#include <pmath/Vector2.hpp>
#include <pmath/Vector3.hpp>
#include <pmath/Vector4.hpp>

#include <pmath/Matrix2.hpp>
#include <pmath/Matrix3.hpp>

#include <iostream>

namespace pmath
{
    template<typename T>
    class Matrix4
    {
    public:
        Matrix4();
        Matrix4(const T& a11, const T& a12, const T& a13, const T& a14,
                const T& a21, const T& a22, const T& a23, const T& a24,
                const T& a31, const T& a32, const T& a33, const T& a34,
                const T& a41, const T& a42, const T& a43, const T& a44);
        Matrix4(const Vector4<T>& row1, const Vector4<T>& row2, const Vector4<T>& row3, const Vector4<T>& row4);
        explicit Matrix4(const Matrix2<T>& matrix);
        explicit Matrix4(const Matrix3<T>& matrix);
        Matrix4(const Matrix4<T>& matrix);
        template<typename T2>
        Matrix4(const Matrix4<T2>& matrix);
        ~Matrix4();

        static const Matrix4<T> identity;
        bool isIdentity() const;

        T determinant() const;

        Matrix4<T> transpose() const;
        static Matrix4<T> transpose(const Matrix4<T>& matrix);

        Matrix4<T> cofactor() const;
        static Matrix4<T> cofactor(const Matrix4<T>& matrix);

        Matrix4<T> inverse() const;
        static Matrix4<T> inverse(const Matrix4<T>& matrix);
        
        Matrix3<T> getMatrix3(const unsigned int rowToRemove = 2, const unsigned int columnToRemove = 2) const;

        const T* ptr() const;

        #pragma region Operators
        // Comparison
        bool operator ==(const Matrix4<T>& right) const;
        bool operator !=(const Matrix4<T>& right) const;


        // Assingment
        Matrix4<T>& operator =(const Matrix4<T>& right);
        Matrix4<T>& operator +=(const Matrix4<T>& right);
        Matrix4<T>& operator -=(const Matrix4<T>& right);
        Matrix4<T>& operator *=(const T& right);
        Matrix4<T>& operator /=(const T& right);


        // Arithmetic
        Matrix4<T> operator +(const Matrix4<T>& right) const;
        Matrix4<T> operator -(const Matrix4<T>& right) const;
        Matrix4<T> operator *(const Matrix4<T>& right) const;
        Matrix4<T> operator *(const T& right) const;
        Vector2<T> operator *(const Vector2<T>& right) const;
        Vector3<T> operator *(const Vector3<T>& right) const;
        Vector4<T> operator *(const Vector4<T>& right) const;
        Matrix4<T> operator /(const T& right) const;


        // Member access
        Vector4<T>& operator [](const unsigned int index);
        const Vector4<T>& operator [](const unsigned int index) const;
        #pragma endregion

        static const unsigned int COLUMNS = 4;
        static const unsigned int ROWS = 4;

    private:
        Vector4<T> r1, r2, r3, r4;
    };

    template<typename T>
    Matrix4<T> operator *(const T& left, const Matrix4<T>& right);

    template<typename T>
    Vector2<T>& operator *=(Vector2<T>& left, const Matrix4<T>& right);

    template<typename T>
    Vector3<T>& operator *=(Vector3<T>& left, const Matrix4<T>& right);

    template<typename T>
    Vector4<T>& operator *=(Vector4<T>& left, const Matrix4<T>& right);

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Matrix4<T>& right);


    typedef Matrix4<float>          Mat4;
    typedef Matrix4<double>         Mat4d;
    typedef Matrix4<int>            Mat4i;
    typedef Matrix4<unsigned int>   Mat4u;
}

#include <pmath/inl/Matrix4.inl>
#endif