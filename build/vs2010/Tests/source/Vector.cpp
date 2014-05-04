#include <catch.hpp>

#include <pmath/Vector.hpp>

using namespace pmath;

TEST_CASE("Vector2 tests", "[vector]")
{
    SECTION("Boolean tests")
    {
        CHECK(Vec2(1, 1) != Vec2(2, 1));
        CHECK(Vec2(2, 2) == Vec2(2, 2));
        CHECK_FALSE(Vec2(2, 2) == Vec2(1, 2));
        CHECK_FALSE(Vec2(2, 2) != Vec2(2, 2));
    }

    SECTION("Basic operators")
    {
        Vec2 vec1(5, 10);
        Vec2 vec2(2, 4);

        CHECK((vec1 - vec2) == Vec2(3, 6));
        CHECK((vec1 + vec2) == Vec2(7, 14));
        CHECK((vec1 * 2) == Vec2(10, 20));
        CHECK((vec2 / 2) == Vec2(1, 2));
        

        vec1 *= 2;
        CHECK(vec1 == Vec2(10, 20));
        vec2 /= 2;
        CHECK(vec2 == Vec2(1, 2));


        vec1 = Vec2(5, 10);
        vec2 = Vec2(2, 4);
        CHECK(vec1 == Vec2(5, 10));
        CHECK(vec2 == Vec2(2, 4));

        vec1 += Vec2(5, 5);
        vec2 -= Vec2(2, 4);
        CHECK(vec1 == Vec2(10, 15));
        CHECK(vec2 == Vec2());
        CHECK((vec2 += Vec2i(1,2)) == Vec2u(1,2));

        CHECK(Vec2(1, 2) > Vec2(1, 1));
        CHECK(Vec2(1, 2) >= Vec2(1, 2));
        CHECK(Vec2(1, 2) <= Vec2(2, 2));
        CHECK(Vec2(1, 2) < Vec2(-2, -2));

        vec1 = Vec2(1, 2);
        CHECK(vec1[0] == 1);
        CHECK(vec1[1] == 2);
    }

    SECTION("Dot, cross and length")
    {
        Vec2 vec1(2, 2);
        Vec2 vec2(5, 5);

        CHECK(vec1.dot(vec2) == 20);
        CHECK(Vec2::dot(vec1, vec2) == 20);

        CHECK(vec1.length() == sqrt(8.0));
        CHECK(vec2.lengthSquared() == 50);

        Vec2 a(1,2), b(9,8);
        CHECK(a.cross(b) == -10);
        CHECK(Vec2::cross(b, a) == 10);

        CHECK(Vec2::distance(Vec2(1, 2), Vec2(2,1)) == sqrt(2.0));
    }

    SECTION("Normals")
    {
        Vec2 vec(5, 9);
        CHECK(vec.unitVector() == Vec2(5 / sqrt(106.f), 9 / sqrt(106.f)));
        CHECK(vec.normalize() == Vec2(5 / sqrt(106.f), 9 / sqrt(106.f)));
        CHECK(vec.isUnitVector());
    }
}


TEST_CASE("Vector3 tests", "[vector]")
{
    SECTION("Boolean tests")
    {
        Vec3 vec1(1, 2, 3);
        Vec3 vec2(3, 2, 1);

        CHECK(vec1 == Vec3(1, 2, 3));
        CHECK(vec1 != vec2);
        CHECK_FALSE(vec1 == vec2);
        CHECK_FALSE(vec2 != vec2);
    }

    SECTION("Basic operators")
    {
        Vec3 vec1(5, 10, 15);
        Vec3 vec2(2, 4, 8);

        CHECK(-vec1 == Vec3(-5, -10, -15));
        CHECK((vec1 - vec2) == Vec3(3, 6, 7));
        CHECK_FALSE((vec1 - vec2) == Vec3(7, 6, 3));
        CHECK((vec1 + vec2) == Vec3(7, 14, 23));
        CHECK_FALSE((vec1 + vec2) == Vec3(23, 14, 7));
        CHECK((vec1 * 2) == Vec3(10, 20, 30));
        CHECK((vec2 / 2) == Vec3(1, 2, 4));


        vec1 *= 2;
        CHECK(vec1 == Vec3(10, 20, 30));
        vec2 /= 2;
        CHECK(vec2 == Vec3(1, 2, 4));


        vec1 = Vec3(5, 10, 15);
        vec2 = Vec3(2, 4, 8);
        REQUIRE(vec1 == Vec3(5, 10, 15));
        REQUIRE(vec2 == Vec3(2, 4, 8));

        vec1 += Vec3(5, 5, 5);
        vec2 -= Vec3(2, 4, 8);
        CHECK(vec1 == Vec3(10, 15, 20));
        CHECK(vec2 == Vec3());
        CHECK((vec2 += Vec3i(1,2,3)) == Vec3u(1,2,3));


        CHECK(Vec3(1, 2, 3) > Vec3(1, 2, 2));
        CHECK(Vec3(1, 2, 3) >= Vec3(1, 2, 3));
        CHECK(Vec3(1, 2, 3) <= Vec3(2, 2, 3));
        CHECK(Vec3(1, 2, 3) < Vec3(-2, -2, -4));

        vec1 = Vec3(1, 2, 3);
        CHECK(vec1[1] == 2);
        CHECK(vec1[2] == 3);
    }

    SECTION("Dot, cross and length")
    {
        Vec3 vec1(1, 2, 3);
        Vec3 vec2(7, 8, 9);

        CHECK(vec1.dot(vec2) == 50);
        CHECK(Vec3::dot(vec2, vec1) == 50);

        CHECK(vec1.length() == sqrt(14.0));
        CHECK(vec2.lengthSquared() == 194);

        CHECK(vec1.cross(vec2) == Vec3(-6, 12, -6));
        CHECK(Vec3::cross(vec2, vec1) == Vec3(6, -12, 6));

        CHECK(Vec3::distance(Vec3(1, 2, 3), Vec3(3, 2, 1)) == 2*sqrt(2.0));
    }

    SECTION("Normals")
    {
        Vec3 vec(5, 9, 7);
        CHECK(vec.unitVector() == Vec3(sqrt(5.f / 31.f), 9 / sqrt(155.f), 7 / sqrt(155.f)));
        CHECK(vec.normalize() == Vec3(sqrt(5.f / 31.f), 9 / sqrt(155.f), 7 / sqrt(155.f)));
        CHECK(vec.isUnitVector());
    }
}


TEST_CASE("Vector4 tests", "[vector]")
{
    SECTION("Boolean tests")
    {
        Vec4 vec1(1, 2, 3, 4);
        Vec4 vec2(4, 3, 2, 1);

        CHECK(vec1 == Vec4(1, 2, 3, 4));
        CHECK(vec1 != vec2);
        CHECK_FALSE(vec1 == vec2);
        CHECK_FALSE(vec2 != vec2);
    }

    SECTION("Basic operators")
    {
        Vec4 vec1(5, 10, 15, 20);
        Vec4 vec2(2, 4, 8, 16);

        CHECK(-vec1 == Vec4(-5, -10, -15, -20));
        CHECK((vec1 - vec2) == Vec4(3, 6, 7, 4));
        CHECK_FALSE((vec1 - vec2) == Vec4(4, 7, 6, 3));
        CHECK((vec1 + vec2) == Vec4(7, 14, 23, 36));
        CHECK_FALSE((vec1 + vec2) == Vec4(36, 23, 14, 7));
        CHECK((vec1 * 2) == Vec4(10, 20, 30, 40));
        CHECK((vec2 / 2) == Vec4(1, 2, 4, 8));


        vec1 *= 2;
        CHECK(vec1 == Vec4(10, 20, 30, 40));
        vec2 /= 2;
        CHECK(vec2 == Vec4(1, 2, 4, 8));


        vec1 = Vec4(5, 10, 15, 20);
        vec2 = Vec4(2, 4, 8, 16);
        REQUIRE(vec1 == Vec4(5, 10, 15, 20));
        REQUIRE(vec2 == Vec4(2, 4, 8, 16));

        vec1 += Vec4(5, 5, 5, 5);
        vec2 -= Vec4(2, 4, 8, 16);
        CHECK(vec1 == Vec4(10, 15, 20, 25));
        CHECK(vec2 == Vec4());
        CHECK((vec2 += Vec4i(1,2,3,4)) == Vec4u(1,2,3,4));

        CHECK(Vec4(1, 2, 3, 4) > Vec4(1, 2, 2, 3));
        CHECK(Vec4(1, 2, 3, 4) >= Vec4(1, 2, 3, 4));
        CHECK(Vec4(1, 2, 3, 4) <= Vec4(2, 2, 3, 4));
        CHECK(Vec4(1, 2, 3, 4) < Vec4(-2, -2, -4, -4));

        vec1 = Vec4(1, 2, 3, 4);
        CHECK(vec1[1] == 2);
        CHECK(vec1[3] == 4);
    }

    SECTION("Dot and length")
    {
        Vec4 vec1(1, 2, 3, 4);
        Vec4 vec2(7, 8, 9, 10);

        CHECK(vec1.dot(vec2) == 90);
        CHECK(Vec4::dot(vec2, vec1) == 90);

        CHECK(vec2.length() == sqrt(294.0));
        CHECK(vec1.lengthSquared() == 30);

        CHECK(Vec4::distance(Vec4(1, 2, 3, 4), Vec4(4,3,2,1)) == 2*sqrt(5.0));
    }

    SECTION("Normals")
    {
        Vec4 vec(5, 9, 3, 1);
        Vec4 result(5 / (2 * sqrt(29.f)), 9 / (2 * sqrt(29.f)),
            3 / (2 * sqrt(29.f)), 1 / (2 * sqrt(29.f)));

        CHECK(vec.unitVector() == result);
        CHECK(vec.normalize() == result);
        CHECK(vec.isUnitVector());
    }
}