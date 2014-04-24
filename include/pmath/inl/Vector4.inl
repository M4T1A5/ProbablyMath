#include <pmath/Vector4.hpp>
#include <cmath>

namespace pmath
{
    template<typename T>
    inline Vector4<T>::Vector4()
        : x(T()),
          y(T()),
          z(T()),
          w(T())
    { }

    template<typename T>
    inline Vector4<T>::Vector4(T x, T y, T z, T w)
        : x(x),
          y(y),
          z(z),
          w(w)
    { }

    template<typename T>
    inline Vector4<T>::Vector4(T value)
        : x(value),
          y(value),
          z(value),
          w(value)
    { }

    template<typename T>
    inline Vector4<T>::Vector4(const Vector4<T>& vector4)
        : x(vector4.x),
          y(vector4.y),
          z(vector4.z),
          w(vector4.w)
    { }

    template<typename T>
    inline Vector4<T>::~Vector4()
    { }


    // Public
    template<typename T>
    inline const T Vector4<T>::Dot(const Vector4<T>& other) const
    {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    template<typename T>
    inline const T Vector4<T>::Dot(const Vector4<T>& vec1, const Vector4<T>& vec2)
    {
        return vec1.Dot(vec2);
    }

    template<typename T>
    inline const T Vector4<T>::LengthSquared() const
    {
        return pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
    }

    template<typename T>
    inline const T Vector4<T>::Length() const
    {
        return sqrt(LengthSquared());
    }

    template<typename T>
    inline const Vector4<T> Vector4<T>::Normalize()
    {
        return *this = UnitVector();
    }

    template<typename T>
    inline const Vector4<T> Vector4<T>::UnitVector() const
    {
        return *this / Length();
    }


    // Operators
    #pragma region Operators
    // Assingment operators
    template<typename T>
    inline Vector4<T>& Vector4<T>::operator=(const Vector4<T>& right)
    {
        x = right.x;
        y = right.y;
        z = right.z;
        w = right.w;

        return *this;
    }

    template<typename T>
    inline bool Vector4<T>::operator==(const Vector4<T>& right) const
    {
        return x == right.x && y == right.y && z == right.z && w == right.w;
    }

    template<typename T>
    inline bool Vector4<T>::operator!=(const Vector4<T>& right) const
    {
        return x != right.x || y != right.y || z != right.z || w != right.w;
    }

    template<typename T>
    inline Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& right)
    {
        x += right.x;
        y += right.y;
        z += right.z;
        w += right.w;

        return *this;
    }

    template<typename T>
    inline Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& right)
    {
        x -= right.x;
        y -= right.y;
        z -= right.z;
        w -= right.w;

        return *this;
    }

    template<typename T>
    inline Vector4<T>& Vector4<T>::operator*=(const T& right)
    {
        x *= right;
        y *= right;
        z *= right;
        w *= right;

        return *this;
    }

    template<typename T>
    inline Vector4<T>& Vector4<T>::operator/=(const T& right)
    {
        x /= right;
        y /= right;
        z /= right;
        w /= right;

        return *this;
    }


    // Arithmetic operators
    template<typename T>
    inline Vector4<T> Vector4<T>::operator+(const Vector4<T>& right) const
    {
        return Vector4<T>(x + right.x, y + right.y, z + right.z, w + right.w);
    }

    template<typename T>
    inline Vector4<T> Vector4<T>::operator-() const
    {
        return Vector4<T>(-x, -y, -z, -w);
    }

    template<typename T>
    inline Vector4<T> Vector4<T>::operator-(const Vector4<T>& right) const
    {
        return Vector4<T>(x - right.x, y - right.y, z - right.z, w - right.w);
    }

    template<typename T>
    inline Vector4<T> Vector4<T>::operator*(const T& right) const
    {
        return Vector4<T>(x * right, y * right, z * right, w * right);
    }

    template<typename T>
    inline Vector4<T> Vector4<T>::operator/(const T& right) const
    {
        return Vector4<T>(x / right, y / right, z / right, w / right);
    }

    template<typename T>
    inline Vector4<T> operator*(const T& left, const Vector4<T>& right)
    {
        return right * left;
    }

    template<typename T>
    inline std::ostream& operator<<(std::ostream& out, const Vector4<T>& right)
    {
        out << "(" << right.x << ", " << right.y << ", " << right.z << ", " << right.w << ")";

        return out;
    }
    #pragma endregion
}