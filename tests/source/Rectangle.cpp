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
    }

    SECTION("Less important functions")
    {
        Rect rect(100, 200, 100, 100);

        CHECK(rect.getLeft() == 100);
        CHECK(rect.getRight() == 200);
        CHECK(rect.getTop() == 200);
        CHECK(rect.getBottom() == 300);
        CHECK(rect.area() == 10000);
        CHECK(rect.center() == pmath::Vec2(150, 250));
        CHECK(rect.center<double>() == pmath::Vec2d(150, 250));
    }

    SECTION("Intersect and contains")
    {
        CHECK(Rect(0, 0, 100, 100).intersects(Rect(0, 0, 50, 50)));
        CHECK(Rect(0, 0, 100, 100).intersects(Rect(0, 0, 100, 100)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(101, 101, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(101, 0, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(0, 101, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(-51, -51, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(0, -51, 50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).intersects(Rect(-51, 0, 50, 50)));

        CHECK(Rect(0, 0, 100, 100).contains(Vec2(50, 50)));
        CHECK_FALSE(Rect(0, 0, 100, 100).contains(Vec2(101, 101)));

        CHECK(Rect(0, 0, 100, 100).contains(Rect(25, 25, 25, 25)));
        CHECK(Rect(0, 0, 100, 100).contains(Rect(0, 0, 100, 100)));
        CHECK_FALSE(Rect(0, 0, 100, 100).contains(Rect(101, 101, 100, 100)));

        Rect intersection;
        Rect(0, 0, 100, 100).intersects(Rect(75, 75, 100, 100), intersection);
        CHECK(intersection == Rect(75, 75, 25, 25));
        Rect(0, 0, 100, 100).intersects(Rect(-25, -25, 50, 50), intersection);
        CHECK(intersection == Rect(0, 0, 25, 25));
    }
}