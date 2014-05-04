#include <pmath/Util.hpp>

#include <cmath>

namespace pmath
{
    // Disable unreferenced parameter warning for this function
    #pragma warning(disable: 4100)
    template<typename T>
    inline bool equals(const T a, const T b, const T tolerance)
    {
        return a == b;
    }
    #pragma warning(default: 4100) // Enable the warning again

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