#include <pmath/Util.hpp>
#include <pmath/Constants.hpp>

#include <cmath>

namespace pmath
{
    template<typename T>
    inline bool equals(const T a, const T b, const T tolerance = T(0.001))
    {

        //return a == b;
        return std::abs(a - b) <= tolerance;
    }

    //template<>
    //inline bool equals<float>(const float a, const float b, const float tolerance)
    //{
    //    return abs(a - b) <= tolerance;
    //}
    //
    //template<>
    //inline bool equals<double>(const double a, const double b, const double tolerance)
    //{
    //    return abs(a - b) <= tolerance;
    //}

    template<typename T>
    T degreesToRadians(const T& degrees)
    {
        return (degrees / 180) * pi<T>();
    }

    template<typename T>
    T radiansToDegrees(const T& radians)
    {
        return (radians * 180) / pi<T>();
    }

    template<typename T>
    T cos(const T& angle)
    {
        return std::cos(degreesToRadians<T>(angle));
    }

    template<typename T>
    T sin(const T& angle)
    {
        return std::sin(degreesToRadians<T>(angle));
    }
}