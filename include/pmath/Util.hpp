#pragma once
#ifndef UTIL_PMATH_H
#define UTIL_PMATH_H

namespace pmath
{
    // Test the equality of 2 variables
    // Mostly needed for floating point values
    template<typename T>
    bool equals(const T a, const T b, const T tolerance = T(0.001));

    // Specialization for float
    template<>
    bool equals<float>(const float a, const float b, const float tolerance);

    // Specialization for double
    template<>
    bool equals<double>(const double a, const double b, const double tolerance);
}

#include <pmath/inl/Util.inl>
#endif