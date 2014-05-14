#include "../Util.hpp"
#include "../Constants.hpp"

#include <cmath>

namespace pmath
{
#if _MSC_VER <= 1600
    template<typename T>
    inline bool equals(const T a, const T b, const T tolerance = T(0.001))
#elif _MSC_VER > 1600
    template<typename T>
    inline bool equals(const T a, const T b, const T tolerance)
#endif
    {
        return std::abs(a - b) <= tolerance;
    }

    template<typename T>
    inline T degreesToRadians(const T& degrees)
    {
        return (degrees / 180) * pi<T>();
    }

    template<typename T>
    inline T radiansToDegrees(const T& radians)
    {
        return (radians * 180) / pi<T>();
    }

    template<typename T>
    inline T cos(const T& angle)
    {
        return std::cos(degreesToRadians<T>(angle));
    }

    template<typename T>
    inline T acos(const T& value)
    {
        return radiansToDegrees<T>(std::acos(value));
    }

    template<typename T>
    inline T sin(const T& angle)
    {
        return std::sin(degreesToRadians<T>(angle));
    }

    template<typename T>
    inline T asin(const T& value)
    {
        return radiansToDegrees<T>(std::asin(value));
    }

    template<typename T>
    inline T tan(const T& angle)
    {
        return std::tan(degreesToRadians<T>(angle));
    }

    template<typename T>
    inline T atan(const T& value)
    {
        return radiansToDegrees<T>(std::atan(value));
    }


    template<typename T>
    inline T maximum(const T& a, const T& b)
    {
        if (a > b)
            return a;

        return b;
    }

    template<typename T>
    inline T minimum(const T& a, const T& b)
    {
        if (a < b)
            return a;

        return b;
    }

    template<typename T>
    inline T clamp(const T& value, const T& min, const T& max)
    {
        if (value > max)
            return max;
        else if (value < min)
            return min;

        return value;
    }
}