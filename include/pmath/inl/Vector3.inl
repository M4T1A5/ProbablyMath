#include <pmath/Vector3.hpp>
#include <cmath>

namespace pmath
{
    template<typename T>
    inline Vector3<T>::Vector3()
        : x(T()),
          y(T()),
          z(T())
    { }

    template<typename T>
    inline Vector3<T>::Vector3(T x, T y, T z)
        : x(x),
          y(y),
          z(z)
    { }

    template<typename T>
    inline Vector3<T>::Vector3(T value)
        : x(value),
          y(value),
          z(value)
    { }

    template<typename T>
    inline Vector3<T>::Vector3(const Vector3<T>& vector3)
        : x(vector3.x),
          y(vector3.y),
          z(vector3.z)
    { }

    template<typename T>
    inline Vector3<T>::~Vector3()
    { }


    // Public
    template<typename T>
    inline const T Vector3<T>::Dot(const Vector3<T>& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    template<typename T>
    inline const T Vector3<T>::Dot(const Vector3<T>& vec1, const Vector3<T>& vec2)
    {
        return vec1.Dot(vec2);
    }

    template<typename T>
    inline const Vector3<T> Vector3<T>::Cross(const Vector3<T>& other) const
    {
        return Vector3<T>(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    template<typename T>
    inline const Vector3<T> Vector3<T>::Cross(const Vector3<T>& vec1, const Vector3<T>& vec2)
    {
        return vec1.Cross(vec2);
    }

    template<typename T>
    inline const T Vector3<T>::LengthSquared() const
    {
        return pow(x, 2) + pow(y, 2) + pow(z, 2);
    }

    template<typename T>
    inline const T Vector3<T>::Length() const
    {
        return sqrt(LengthSquared());
    }


    // Operators
    #pragma region Operators
    // Assingment operators
    template<typename T>
    inline Vector3<T>& Vector3<T>::operator=(const Vector3<T>& right)
    {
        x = right.x;
        y = right.y;
        z = right.z;

        return *this;
    }

    template<typename T>
    inline bool Vector3<T>::operator==(const Vector3<T>& right) const
    {
        return x == right.x && y == right.y && z == right.z;
    }

    template<typename T>
    inline bool Vector3<T>::operator!=(const Vector3<T>& right) const
    {
        return x != right.x || y != right.y || z != right.z;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& right)
    {
        x += right.x;
        y += right.y;
        z += right.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& right)
    {
        x -= right.x;
        y -= right.y;
        z -= right.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator*=(const T& right)
    {
        x *= right;
        y *= right;
        z *= right;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator/=(const T& right)
    {
        x /= right;
        y /= right;
        z /= right;

        return *this;
    }


    // Arithmetic operators
    template<typename T>
    inline Vector3<T> Vector3<T>::operator+(const Vector3<T>& right) const
    {
        return Vector3<T>(x + right.x, y + right.y, z + right.z);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator-() const
    {
        return Vector3<T>(-x, -y, -z);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& right) const
    {
        return Vector3<T>(x - right.x, y - right.y, z - right.z);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator*(const T& right) const
    {
        return Vector3<T>(x * right, y * right, z * right);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator/(const T& right) const
    {
        return Vector3<T>(x / right, y / right, z / right);
    }

    template<typename T>
    inline Vector3<T> operator*(const T& left, const Vector3<T>& right)
    {
        return right * left;
    }

    template<typename T>
    inline std::ostream& operator<<(std::ostream& out, const Vector3<T>& right)
    {
        out << "(" << right.x << ", " << right.y << ", " << right.z << ")";

        return out;
    }
    #pragma endregion
}