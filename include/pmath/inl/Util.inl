#include <pmath/Util.hpp>

namespace pmath
{
    template<typename T>
    inline bool equals(const T& a, const T& b)
    {
        return a == b;
    }

    template<typename T>
    inline bool equals(const float& a, const float& b, const float& tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    template<typename T>
    inline bool equals(const double& a, const double& b, const double& tolerance)
    {
        return abs(a - b) <= tolerance;
    }
}