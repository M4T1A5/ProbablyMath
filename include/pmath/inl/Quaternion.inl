#include <pmath/Quaternion.hpp>
#include <pmath/Util.hpp>

namespace pmath
{
    template<typename T>
    const Quaternion<T> Quaternion<T>::identity = Quaternion<T>();

    template<typename T>
    inline Quaternion<T>::Quaternion()
        : w(T(1))
    { }

    template<typename T>
    inline Quaternion<T>::Quaternion(const T& w, const T& x, const T& y, const T& z)
        : w(w),
          vector(x, y, z)
    { }

    template<typename T>
    inline Quaternion<T>::Quaternion(const T& w, const Vector3<T>& vector)
        : w(w),
          vector(vector)
    { }

    template<typename T>
    inline Quaternion<T>::Quaternion(const Quaternion<T>& quaternion)
        : w(quaternion.w),
          vector(quaternion.vector)
    { }

    template<typename T>
    template<typename T2>
    inline Quaternion<T>::Quaternion(const Quaternion<T2>& quaternion)
        : w(static_cast<T>(quaternion.w)),
          vector(quaternion.vector)
    { }

    template<typename T>
    inline Quaternion<T>::~Quaternion()
    { }


    // Public

    template<typename T>
    inline bool Quaternion<T>::isIdentity() const
    {
        return *this == identity;
    }

    template<typename T>
    inline double Quaternion<T>::lengthSquared() const
    {
        return w*w + vector.lengthSquared();
    }

    template<typename T>
    inline double Quaternion<T>::length() const
    {
        return sqrt(lengthSquared());
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::conjugate() const
    {
        return Quaternion<T>(w, -vector);
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::inverse() const
    {
        // Quaternion inverse is conjugate / |q|^2
        return conjugate() / lengthSquared();
    }

    template<typename T>
    inline Quaternion<T>& Quaternion<T>::normalize()
    {
        return *this = unitQuaternion();
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::unitQuaternion() const
    {
        return *this / length();
    }

    template<typename T>
    inline bool Quaternion<T>::isUnitQuaternion() const
    {
        // LengthSquared returns double.
        // Also sqrt(1) == 1 so we don't need to do that
        return equals<double>(this->lengthSquared(), 1);
    }


    // Operators
    #pragma region Operators
    // Comparison
    template<typename T>
    inline bool Quaternion<T>::operator ==(const Quaternion<T>& right)
    {
        return equals<T>(w, right.w) && vector == right.vector;
    }

    template<typename T>
    inline bool Quaternion<T>::operator !=(const Quaternion<T>& right)
    {
        return !(*this == right)
    }

    // Arithmetic
    template<typename T>
    inline Quaternion<T> Quaternion<T>::operator +(const Quaternion<T>& right)
    {
        return Quaternion<T>(w + right.w, vector + right.vector);
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::operator -(const Quaternion<T>& right)
    {
        return Quaternion<T>(w - right.w, vector - right.vector);
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::operator -()
    {
        return Quaternion<T>(-w , -vector);
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::operator *(const Quaternion<T>& right)
    {
        return Quaternion<T>(w * right.w - vector.dot(right.vector),
            w*right.vector + right.w*vector + vector.cross(right.vector));
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::operator *(const T& right)
    {
        return Quaternion<T>(w * right, vector * right);
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::operator /(const T& right)
    {
        return Quaternion<T>(w / right, vector / right);
    }

    // Assingment
    template<typename T>
    inline Quaternion<T>& Quaternion<T>::operator =(const Quaternion<T>& right)
    {
        w = right.w;
        vector = right.vector;

        return *this;
    }

    template<typename T>
    inline Quaternion<T>& Quaternion<T>::operator +=(const Quaternion<T>& right)
    {
        *this = *this + right;

        return *this;
    }

    template<typename T>
    inline Quaternion<T>& Quaternion<T>::operator -=(const Quaternion<T>& right)
    {
        *this = *this - right;

        return *this;
    }

    template<typename T>
    inline Quaternion<T>& Quaternion<T>::operator *=(const Quaternion<T>& right)
    {
        *this = *this * right;

        return *this;
    }

    template<typename T>
    inline Quaternion<T>& Quaternion<T>::operator *=(const T& right)
    {
        *this = *this * right;

        return *this;
    }

    template<typename T>
    inline Quaternion<T>& Quaternion<T>::operator /=(const T& right)
    {
        *this = *this / right;

        return *this;
    }

    template<typename T>
    Vector3<T> operator *(const Vector3<T>& left, const Quaternion<T>& right)
    {
        const Vector3<T> rightleftCross = right.vector.cross(left);

        return left + 2*(right.w*rightleftCross + right.vector.cross(rightleftCross));
    }

    template<typename T>
    Vector3<T> operator *(const Quaternion<T>& left, const Vector3<T>& right)
    {
        return right * left;
    }

    // Multiply a homogeneous vector e.g. (x,y,z,1)
    template<typename T>
    Vector4<T> operator *(const Vector4<T>& left, const Quaternion<T>& right)
    {
        // Extract x, y and z
        const Vector3<T> vec3(left.x, left.y, left.z);

        return Vector4<T>(vec3 * right, left.w);
    }

    template<typename T>
    Vector4<T> operator *(const Quaternion<T>& left, const Vector4<T>& right)
    {
        return right * left;
    }
    
    template<typename T>
    Vector3<T>& operator *=(Vector3<T>& left, const Quaternion<T>& right)
    {
        left = left * right;

        return left;
    }

    template<typename T>
    Vector4<T>& operator *=(Vector4<T>& left, const Quaternion<T>& right)
    {
        left = left * right;

        return left;
    }
    #pragma endregion
}