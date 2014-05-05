#include <catch.hpp>

#include <pmath/Quaternion.hpp>

using namespace pmath;

TEST_CASE("Quaternion tests", "[quaternion]")
{
    SECTION("Operators")
    {
        CHECK(Quat() == Quat::identity);
    }
}