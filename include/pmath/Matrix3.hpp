#pragma once
#ifndef MATRIX3_PMATH_H
#define MATRIX3_PMATH_H

#include <iostream>

namespace pmath
{
    template<typename T>
    class Matrix3
    {
    public:

        static const unsigned int COLUMNS = 3;
        static const unsigned int ROWS = 3;
    };

    typedef Matrix3<float>          Mat3;
    typedef Matrix3<double>         Mat3d;
    typedef Matrix3<int>            Mat3i;
    typedef Matrix3<unsigned int>   Mat3u;
}

#include <pmath/inl/Matrix3.inl>
#endif