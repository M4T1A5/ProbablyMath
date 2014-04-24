#include <pmath/Vector2.hpp>
#include <cmath>

namespace pmath
{
    template<typename T>
    inline Vector2<T>::Vector2()
        : x(T()),
          y(T())
    { }

    template<typename T>
    inline Vector2<T>::Vector2(T x, T y)
        : x(x),
          y(y)
    { }

    template<typename T>
    inline Vector2<T>::Vector2(T value)
        : x(value),
          y(value)
    { }

    template<typename T>
    inline Vector2<T>::Vector2(const Vector2<T>& vector2)
        : x(vector2.x),
          y(vector2.y)
    { }

    template<typename T>
    inline Vector2<T>::~Vector2()
    { }


    // Public
    template<typename T>
    inline const T Vector2<T>::Dot(const Vector2<T>& other) const
    {
        return x * other.x + y * other.y;
    }
    template<typename T>
    inline const T Vector2<T>::Dot(const Vector2<T>& vec1, const Vector2<T>& vec2)
    {
        return vec1.Dot(vec2);
    }

    template<typename T>
    inline const T Vector2<T>::Cross(const Vector2<T>& other) const
    {
        return (x * other.y) - (y * other.x);
    }

    template<typename T>
    inline const T Vector2<T>::Cross(const Vector2<T>& vec1, const Vector2<T>& vec2)
    {
        return vec1.Cross(vec2);
    }

    template<typename T>
    inline const T Vector2<T>::LengthSquared() const
    {
        return pow(x, 2) + pow(y, 2);
    }

    template<typename T>
    inline const T Vector2<T>::Length() const
    {
        return sqrt(LengthSquared());
    }

    template<typename T>
    inline const Vector2<T> Vector2<T>::Normalize()
    {
        return *this = UnitVector();
    }

    template<typename T>
    inline const Vector2<T> Vector2<T>::UnitVector() const
    {
        return *this / Length();
    }


    // Operators
    #pragma region Operators
    // Comparison operators
    template<typename T>
    inline bool Vector2<T>::operator ==(const Vector2<T>& right) const
    {
        return x == right.x && y == right.y;
    }

    template<typename T>
    inline bool Vector2<T>::operator !=(const Vector2<T>& right) const
    {
        return x != right.x || y != right.y;
    }

    template<typename T>
    inline bool Vector2<T>::operator >(const Vector2<T>& right) const
    {
        return LengthSquared() > right.LengthSquared();
    }

    template<typename T>
    inline bool Vector2<T>::operator <(const Vector2<T>& right) const
    {
        return LengthSquared() < right.LengthSquared();
    }

    template<typename T>
    inline bool Vector2<T>::operator >=(const Vector2<T>& right) const
    {
        return LengthSquared() >= right.LengthSquared();
    }

    template<typename T>
    inline bool Vector2<T>::operator <=(const Vector2<T>& right) const
    {
        return LengthSquared() <= right.LengthSquared();
    }

    // Assingment operators
    template<typename T>
    inline Vector2<T>& Vector2<T>::operator =(const Vector2<T>& right)
    {
        x = right.x;
        y = right.y;

        return *this;
    }

    template<typename T>
    inline Vector2<T>& Vector2<T>::operator +=(const Vector2<T>& right)
    {
        x += right.x;
        y += right.y;

        return *this;
    }

    template<typename T>
    inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& right)
    {
        x -= right.x;
        y -= right.y;

        return *this;
    }

    template<typename T>
    inline Vector2<T>& Vector2<T>::operator*=(const T& right)
    {
        x *= right;
        y *= right;

        return *this;
    }

    template<typename T>
    inline Vector2<T>& Vector2<T>::operator/=(const T& right)
    {
        x /= right;
        y /= right;

        return *this;
    }


    // Arithmetic operators
    template<typename T>
    inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& right) const
    {
        return Vector2<T>(x + right.x, y + right.y);
    }

    template<typename T>
    inline Vector2<T> Vector2<T>::operator-() const
    {
        return Vector2<T>(-x, -y);
    }

    template<typename T>
    inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& right) const
    {
        return Vector2<T>(x - right.x, y - right.y);
    }   

    template<typename T>
    inline Vector2<T> Vector2<T>::operator*(const T& right) const
    {
        return Vector2<T>(x * right, y * right);
    }

    template<typename T>
    inline Vector2<T> Vector2<T>::operator/(const T& right) const
    {
        return Vector2<T>(x / right, y / right);
    }

    template<typename T>
    inline Vector2<T> operator*(const T& left, const Vector2<T>& right)
    {
        return right * left;
    }
    
    template<typename T>
    inline std::ostream& operator<<(std::ostream& out, const Vector2<T>& right)
    {
        out << "(" << right.x << ", " << right.y << ")";

        return out;
    }
    #pragma endregion
}