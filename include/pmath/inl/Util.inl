#pragma once
#include <cmath>

namespace pmath
{
    template<typename T>
    bool equals(const T a, const T b, const T tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    template<typename T>
    T abs(const T& value)
    {
        return std::abs(value);
    }

    template<typename T>
    T max(const T& a, const T& b)
    {
        if (a > b)
            return a;

        return b;
    }

    template<typename T>
    T min(const T& a, const T& b)
    {
        if (a < b)
            return a;

        return b;
    }

    template<typename T>
    T clamp(const T& value, const T& min, const T& max)
    {
        if (value > max)
            return max;
        else if (value < min)
            return min;

        return value;
    }

    template<typename T, typename T2>
    T lerp(const T& a, const T& b, const T2& t)
    {
        return (1 - t) * a + t * b;
    }
}
