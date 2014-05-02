#pragma once
#ifndef MATRIX2_PMATH_H
#define MATRIX2_PMATH_H

#include <pmath/Vector2.hpp>
#include <iostream>

namespace pmath
{
    template<typename T>
    class Matrix2
    {
    public:
        Matrix2();
        Matrix2(const T& a11, const T& a12,
                const T& a21, const T& a22);
        Matrix2(const Vector2<T>& row1, const Vector2<T>& row2);
        Matrix2(const Matrix2<T>& matrix);
        template<typename T2>
        Matrix2(const Matrix2<T2>& matrix);
        ~Matrix2();

        static const Matrix2<T> identity;
        bool isIdentity() const;

        T determinant() const;

        Matrix2<T> transpose() const;
        static Matrix2<T> transpose(const Matrix2<T>& matrix);

        Matrix2<T> cofactor() const;
        static Matrix2<T> cofactor(const Matrix2<T>& matrix);

        Matrix2<T> inverse() const;
        static Matrix2<T> inverse(const Matrix2<T>& matrix);

        const T* ptr() const;

        #pragma region Operators
        // Comparison
        bool operator ==(const Matrix2<T>& right) const;
        bool operator !=(const Matrix2<T>& right) const;


        // Assingment
        Matrix2<T>& operator =(const Matrix2<T>& right);
        Matrix2<T>& operator +=(const Matrix2<T>& right);
        Matrix2<T>& operator -=(const Matrix2<T>& right);
        Matrix2<T>& operator *=(const T& right);
        Matrix2<T>& operator /=(const T& right);


        // Arithmetic
        Matrix2<T> operator +(const Matrix2<T>& right) const;
        Matrix2<T> operator -(const Matrix2<T>& right) const;
        Matrix2<T> operator *(const Matrix2<T>& right) const;
        Matrix2<T> operator *(const T& right) const;
        Vector2<T> operator *(const Vector2<T>& right) const;
        Matrix2<T> operator /(const T& right) const;


        // Member access
        Vector2<T>& operator [](const unsigned int index);
        const Vector2<T>& operator [](const unsigned int index) const;
        #pragma endregion

        static const unsigned int COLUMNS = 2;
        static const unsigned int ROWS = 2;
    private:
        Vector2<T> r1, r2;
    };

    template<typename T>
    Matrix2<T> operator *(const T& left, const Matrix2<T>& right);

    template<typename T>
    Vector2<T>& operator *=(Vector2<T>& left, const Matrix2<T>& right);

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Matrix2<T>& right);

    typedef Matrix2<float>          Mat2;
    typedef Matrix2<double>         Mat2d;
    typedef Matrix2<int>            Mat2i;
    typedef Matrix2<unsigned int>   Mat2u;
}

#include <pmath/inl/Matrix2.inl>
#endif