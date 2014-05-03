#pragma once
#ifndef QUATERNION_PMATH_H
#define QUATERNION_PMATH_H

#include <iostream>

namespace pmath
{
    template<typename T>
    class Quaternion
    {
    public:
        Quaternion();
        ~Quaternion();

    private:
    };
}

#include <pmath/inl/Quaternion.inl>
#endif