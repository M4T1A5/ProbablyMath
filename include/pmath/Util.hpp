#pragma once
#ifndef UTIL_PMATH_H
#define UTIL_PMATH_H

namespace pmath
{
    // Test the equality of 2 variables
    // Mostly needed for floating point values
    template<typename T>
    bool equals(const T& a, const T& b);

    // Specialization for float
    template<typename T>
    bool equals(const float& a, const float& b, const float& tolerance = 0.001f);

    // Specialization for double
    template<typename T>
    bool equals(const double& a, const T& b, const double& tolerance = 0.001);
}

#include <pmath/inl/Util.inl>
#endif