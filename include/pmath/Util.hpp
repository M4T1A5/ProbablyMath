#pragma once
#ifndef UTIL_PMATH_H
#define UTIL_PMATH_H

namespace pmath
{
    // Test the equality of 2 variables
    // Mostly needed for floating point values
    template<typename T>
    bool equals(const T a, const T b, const T tolerance = T(0.001));

    template<typename T>
    T abs(const T& value);

    template<typename T>
    T max(const T& a, const T& b);

    template<typename T>
    T min(const T& a, const T& b);

    template<typename T>
    T clamp(const T& value, const T& min, const T& max);

    template<typename T, typename T2>
    T lerp(const T& a, const T& b, const T2& t);
}

#include "inl/Util.inl"
#endif
