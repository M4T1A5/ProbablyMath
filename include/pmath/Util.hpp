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

    template<typename T>
    T degreesToRadians(const T& degrees);

    template<typename T>
    T radiansToDegrees(const T& radians);

    template<typename T>
    T cos(const T& angle);

    template<typename T>
    T sin(const T& angle);
}

#include <pmath/inl/Util.inl>
#endif