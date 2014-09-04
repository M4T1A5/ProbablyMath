#include <catch.hpp>

#include <pmath/Rectangle.hpp>
#include <iostream>

using namespace pmath;

TEST_CASE("Rectangle tests", "[rectangle]")
{
    SECTION("Operators")
    {
        CHECK(Rect() == Rect());
        CHECK(Rect(1, 2, 3, 4) == Rect(1, 2, 3, 4));
        CHECK(Rect(1, 2, 3, 4) != Rect());
        CHECK_FALSE(Rect(1, 2, 3, 4) == Rect());
        CHECK_FALSE(Rect(1, 2, 3, 4) != Rect(1, 2, 3, 4));

        CHECK(Rect(Vec2i(0, 0), Vec2d(10, 10)) == Rect(0, 0, 10, 10));
        CHECK(Rect(Recti(0, 0, 10, 10)) == Rect(0, 0, 10, 10));
        Rect rect;
        rect = Rect(0, 0, 10, 10);
        CHECK(rect == Rect(0, 0, 10, 10));

        std::cout << Rect(0, 0, 100, 100) << std::endl;
    }

    SECTION("Less important functions")
    {
        Rect rect(100, 200, 100, 100);

        CHECK(rect.getLeft() == 100);
        CHECK(rect.getRight() == 200);
        CHECK(rect.getTop() == 200);
        CHECK(rect.getBottom() == 300);
        CHECK(rect.area() == 10000);
    }

    SECTION("Intersect and contains")
    {
        CHECK(Rect(0, 0, 100, 100).intersects(Rect(0, 0, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(101, 101, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(101, 0, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(0, 101, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(-51, -51, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(0, -51, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(-51, 0, 50, 50)));

        CHECK(Rect(0, 0, 100, 100).contains(Vec2(50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).contains(Vec2(101, 101)));
    }
}