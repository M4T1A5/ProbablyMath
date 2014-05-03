#pragma once
#ifndef QUATERNION_PMATH_H
#define QUATERNION_PMATH_H

#include <pmath/Vector3.hpp>
#include <pmath/Vector4.hpp>

#include <iostream>

namespace pmath
{
    template<typename T>
    class Quaternion
    {
    public:
        Quaternion();
        Quaternion(T w, T x, T y, T z);
        Quaternion(T w, Vector3<T> vector);
        Quaternion(const Quaternion<T>& quaternion);
        template<typename T2>
        Quaternion(const Quaternion<T2>& quaternion);
        ~Quaternion();

        T w;
        Vector3<T> vector;
    };

    typedef Quaternion<float>   quat;
    typedef Quaternion<float>   quatf;
    typedef Quaternion<double>  quatd;
}

#include <pmath/inl/Quaternion.inl>
#endif