#include <pmath/Matrix3.hpp>
#include <cassert>

namespace pmath
{
    template<typename T>
    const Matrix3<T> Matrix3<T>::identity = Matrix3<T>();

    template<typename T>
    inline Matrix3<T>::Matrix3()
        : r1(T(1), T(0), T(0)),
          r2(T(0), T(1), T(0)),
          r3(T(0), T(0), T(1))
    { }

    template<typename T>
    inline Matrix3<T>::Matrix3(const T& a11, const T& a12, const T& a13,
                               const T& a21, const T& a22, const T& a23,
                               const T& a31, const T& a32, const T& a33)
        : r1(a11, a12, a13),
          r2(a21, a22, a23),
          r3(a31, a32, a33)
    { }

    template<typename T>
    inline Matrix3<T>::Matrix3(const Vector3<T>& row1, const Vector3<T>& row2, const Vector3<T>& row3)
        : r1(row1),
          r2(row2),
          r3(row3)
    { }

    template<typename T>
    inline Matrix3<T>::Matrix3(const Matrix3<T>& matrix)
        : r1(matrix.r1),
          r2(matrix.r2),
          r3(matrix.r3)
    { }

    template<typename T>
    template<typename T3>
    inline Matrix3<T>::Matrix3(const Matrix3<T3>& matrix)
        : r1(matrix[0]),
          r2(matrix[1]),
          r3(matrix[2])
    { }

    template<typename T>
    inline Matrix3<T>::~Matrix3()
    { }

    template<typename T>
    inline T Matrix3<T>::determinant() const
    {
        return (*this)[0][0] * (*this)[1][1] * (*this)[2][2] - 
            (*this)[0][0] * (*this)[1][2] * (*this)[2][1] -
            (*this)[0][1] * (*this)[1][0] * (*this)[2][2] +
            (*this)[0][1] * (*this)[1][2] * (*this)[2][0] +
            (*this)[0][2] * (*this)[1][0] * (*this)[2][1] -
            (*this)[0][2] * (*this)[1][1] * (*this)[2][0];

    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::transpose() const
    {
        return Matrix3<T>
            (
                (*this)[0][0], (*this)[1][0], (*this)[2][0],
                (*this)[0][1], (*this)[1][1], (*this)[2][1],
                (*this)[0][2], (*this)[1][2], (*this)[2][2]
            );
    }

    template<typename T>
    inline Matrix3<T> transpose(const Matrix3<T>& matrix)
    {
        return matrix.transpose();
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::cofactor() const
    {
        return Matrix3<T>
            (
                (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1],
                (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2],
                (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1],

                (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2],
                (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0],
                (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2],

                (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0],
                (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1],
                (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0]
            );
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::cofactor(const Matrix3<T>& matrix)
    {
        return matrix.cofactor();
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::inverse() const
    {
        assert(determinant() != 0);
        return 1/determinant() * cofactor();
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::inverse(const Matrix3<T>& matrix)
    {
        return matrix.inverse();
    }

    template<typename T>
    const T* Matrix3<T>::ptr() const
    {
        return (*this)[0][0];
    }


    // Operators
    #pragma region Operators
    // Comparison
    template<typename T>
    inline bool Matrix3<T>::operator ==(const Matrix3<T>& right) const
    {
        return r1 == right.r1 && r2 == right.r2 && r3 == right.r3;
    }

    template<typename T>
    inline bool Matrix3<T>::operator !=(const Matrix3<T>& right) const
    {
        return !(*this == right);
    }


    // Assingment
    template<typename T>
    inline Matrix3<T>& Matrix3<T>::operator =(const Matrix3<T>& right)
    {
        r1 = right.r1;
        r2 = right.r2;
        r3 = right.r3;

        return *this;
    }

    template<typename T>
    inline Matrix3<T>& Matrix3<T>::operator +=(const Matrix3<T>& right)
    {
        r1 += right.r1;
        r2 += right.r2;
        r3 += right.r3;

        return *this;
    }

    template<typename T>
    inline Matrix3<T>& Matrix3<T>::operator -=(const Matrix3<T>& right)
    {
        r1 -= right.r1;
        r2 -= right.r2;
        r3 -= right.r3;

        return *this;
    }

    template<typename T>
    inline Matrix3<T>& Matrix3<T>::operator *=(const Matrix3<T>& right)
    {
        *this = *this * right;

        return *this;
    }

    template<typename T>
    inline Matrix3<T>& Matrix3<T>::operator *=(const T& right)
    {
        r1 *= right;
        r2 *= right;
        r3 *= right;
    }

    template<typename T>
    inline Matrix3<T>& Matrix3<T>::operator /=(const T& right)
    {
        r1 /= right;
        r2 /= right;
        r3 /= right;

        return *this;
    }


    // Arithmetic
    template<typename T>
    inline Matrix3<T> Matrix3<T>::operator +(const Matrix3<T>& right) const
    {
        return Matrix3<T>(r1 + right.r1, r2 + right.r2, r3 + right.r3);
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::operator -(const Matrix3<T>& right) const
    {
        return Matrix3<T>(r1 - right.r1, r2 - right.r2, r3 - right.r3);
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::operator *(const Matrix3<T>& right) const
    {
        return Matrix3<T>
            (
                (*this)[0][0] * right[0][0] + (*this)[0][1] * right[1][0] + (*this)[0][2] * right[2][0],
                (*this)[0][0] * right[0][1] + (*this)[0][1] * right[1][1] + (*this)[0][2] * right[2][1],
                (*this)[0][0] * right[0][2] + (*this)[0][1] * right[1][2] + (*this)[0][2] * right[2][2],

                (*this)[1][0] * right[0][0] + (*this)[1][1] * right[1][0] + (*this)[1][2] * right[2][0],
                (*this)[1][0] * right[0][1] + (*this)[1][1] * right[1][1] + (*this)[1][2] * right[2][1],
                (*this)[1][0] * right[0][2] + (*this)[1][1] * right[1][2] + (*this)[1][2] * right[2][2],

                (*this)[2][0] * right[0][0] + (*this)[2][1] * right[1][0] + (*this)[2][2] * right[2][0],
                (*this)[2][0] * right[0][1] + (*this)[2][1] * right[1][1] + (*this)[2][2] * right[2][1],
                (*this)[2][0] * right[0][2] + (*this)[2][1] * right[1][2] + (*this)[2][2] * right[2][2]
            );
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::operator *(const T& right) const
    {
        return Matrix3<T>(r1 * right, r2 * right, r3 * right);
    }

    template<typename T>
    Vector2<T> Matrix3<T>::operator *(const Vector2<T>& right) const
    {
        const Vector3<T> result = (*this) * Vector3<T>(right.x, right.y, 1);

        return Vector2<T>(result.x, result.y);
    }

    template<typename T>
    inline Vector3<T> Matrix3<T>::operator *(const Vector3<T>& right) const
    {
        return Vector3<T>
            (
                (*this)[0][0] * right.x + (*this)[0][1] * right.y + (*this)[0][2] * right.z,
                (*this)[1][0] * right.x + (*this)[1][1] * right.y + (*this)[1][2] * right.z,
                (*this)[2][0] * right.x + (*this)[2][1] * right.y + (*this)[2][2] * right.z
            );
    }

    template<typename T>
    inline Matrix3<T> Matrix3<T>::operator /(const T& right) const
    {
        return Matrix3<T>(r1 / right, r2 / right, r3 / right);
    }


    // Member access
    template<typename T>
    inline Vector3<T>& Matrix3<T>::operator [](const unsigned int index)
    {
        assert(index < ROWS);
        return (&r1)[index];
    }

    template<typename T>
    inline const Vector3<T>& Matrix3<T>::operator [](const unsigned int index) const
    {
        assert(index < ROWS);
        return (&r1)[index];
    }


    // Friends
    template<typename T>
    inline Matrix3<T> operator *(const T& left, const Matrix3<T>& right)
    {
        return right * left;
    }

    template<typename T>
    inline std::ostream& operator<<(std::ostream& out, const Matrix3<T>& right)
    {
        for (size_t i = 0; i < Matrix3<T>::ROWS; ++i)
        {
            out << "|";
            for (size_t j = 0; j < Matrix3<T>::COLUMNS; ++j)
            {
                out << right[i][j];
                if (j < Matrix3<T>::COLUMNS - 1)
                    out << ", ";
            }
            out << "|" << std::endl;
        }

        return out;
    }
    #pragma endregion
}