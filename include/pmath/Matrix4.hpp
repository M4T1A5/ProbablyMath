#pragma once
#ifndef MATRIX4_PMATH_H
#define MATRIX4_PMATH_H

#include <iostream>

namespace pmath
{
    template<typename T>
    class Matrix4
    {
    public:

        static const unsigned int COLUMNS = 4;
        static const unsigned int ROWS = 4;
    };

    typedef Matrix4<float>          Mat4;
    typedef Matrix4<double>         Mat4d;
    typedef Matrix4<int>            Mat4i;
    typedef Matrix4<unsigned int>   Mat4u;
}

#include <pmath/inl/Matrix4.inl>
#endif