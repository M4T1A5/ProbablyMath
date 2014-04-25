#include <pmath/Vector3.hpp>
#include <cassert>
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
    inline T Vector3<T>::dot(const Vector3<T>& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    template<typename T>
    inline T Vector3<T>::dot(const Vector3<T>& vec1, const Vector3<T>& vec2)
    {
        return vec1.dot(vec2);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::cross(const Vector3<T>& other) const
    {
        return Vector3<T>(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::cross(const Vector3<T>& vec1, const Vector3<T>& vec2)
    {
        return vec1.cross(vec2);
    }

    template<typename T>
    inline double Vector3<T>::lengthSquared() const
    {
		const double xd = static_cast<double>(x);
		const double yd = static_cast<double>(y);
		const double zd = static_cast<double>(z);
        return xd*xd + yd*yd + zd*zd;
    }

    template<typename T>
    inline double Vector3<T>::length() const
    {
        return sqrt(lengthSquared());
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::normalize()
    {
        return *this = unitVector();
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::unitVector() const
    {
        return *this / length();
    }


    // Operators
    #pragma region Operators
    // Comparison operators
    template<typename T>
    inline bool Vector3<T>::operator ==(const Vector3<T>& right) const
    {
        return x == right.x && y == right.y && z == right.z;
    }

    template<typename T>
    inline bool Vector3<T>::operator !=(const Vector3<T>& right) const
    {
        return x != right.x || y != right.y || z != right.z;
    }

    template<typename T>
    inline bool Vector3<T>::operator >(const Vector3<T>& right) const
    {
        return lengthSquared() > right.lengthSquared();
    }

    template<typename T>
    inline bool Vector3<T>::operator <(const Vector3<T>& right) const
    {
        return lengthSquared() < right.lengthSquared();
    }

    template<typename T>
    inline bool Vector3<T>::operator >=(const Vector3<T>& right) const
    {
        return lengthSquared() >= right.lengthSquared();
    }

    template<typename T>
    inline bool Vector3<T>::operator <=(const Vector3<T>& right) const
    {
        return lengthSquared() <= right.lengthSquared();
    }


    // Assingment operators
    template<typename T>
    inline Vector3<T>& Vector3<T>::operator =(const Vector3<T>& right)
    {
        x = right.x;
        y = right.y;
        z = right.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator +=(const Vector3<T>& right)
    {
        x += right.x;
        y += right.y;
        z += right.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator -=(const Vector3<T>& right)
    {
        x -= right.x;
        y -= right.y;
        z -= right.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator *=(const T& right)
    {
        x *= right;
        y *= right;
        z *= right;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator /=(const T& right)
    {
        x /= right;
        y /= right;
        z /= right;

        return *this;
    }


    // Arithmetic operators
    template<typename T>
    inline Vector3<T> Vector3<T>::operator +(const Vector3<T>& right) const
    {
        return Vector3<T>(x + right.x, y + right.y, z + right.z);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator -() const
    {
        return Vector3<T>(-x, -y, -z);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator -(const Vector3<T>& right) const
    {
        return Vector3<T>(x - right.x, y - right.y, z - right.z);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator *(const T& right) const
    {
        return Vector3<T>(x * right, y * right, z * right);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator /(const T& right) const
    {
        return Vector3<T>(x / right, y / right, z / right);
    }

    template<typename T>
    inline Vector3<T> operator *(const T& left, const Vector3<T>& right)
    {
        return right * left;
    }

    template<typename T>
    inline std::ostream& operator <<(std::ostream& out, const Vector3<T>& right)
    {
        out << "(" << right.x << ", " << right.y << ", " << right.z << ")";

        return out;
    }

    // Member access operators
    template<typename T>
    inline T& Vector3<T>::operator [](const unsigned int index)
    {
        assert(index < COMPONENTS);
        return (&x)[index];
    }

    template<typename T>
    inline const T& Vector3<T>::operator [](const unsigned int index) const
    {
        assert(index < COMPONENTS);
        return (&x)[index];
    }
    #pragma endregion
}