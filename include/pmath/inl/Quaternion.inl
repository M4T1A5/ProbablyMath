#include <pmath/Quaternion.hpp>

namespace pmath
{
    template<typename T>
    inline Quaternion<T>::Quaternion()
        : w(T(1))
    { }

    template<typename T>
    inline Quaternion<T>::Quaternion(T w, T x, T y, T z)
        : w(w),
          vector(Vector3<T>(x,y,z))
    { }

    template<typename T>
    inline Quaternion<T>::Quaternion(T w, Vector3<T> vector)
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

    #pragma region Operators
    // Comparison
    template<typename T>
    inline bool Quaternion<T>::operator ==(const Quaternion<T>& right)
    {
        return w == right.w && vector == right.vector;
    }

    template<typename T>
    inline bool Quaternion<T>::operator !=(const Quaternion<T>& right)
    {
        return !(*this == right)
    }
    #pragma endregion
}