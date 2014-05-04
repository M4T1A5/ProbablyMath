#include <pmath/Util.hpp>

#include <cmath>

namespace pmath
{
    template<typename T>
    inline bool equals(const T a, const T b, const T tolerance)
    {
        return a == b;
    }

    template<>
    inline bool equals<float>(const float a, const float b, const float tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    template<>
    inline bool equals<double>(const double a, const double b, const double tolerance)
    {
        return abs(a - b) <= tolerance;
    }
}