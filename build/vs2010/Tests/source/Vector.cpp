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
	}

	SECTION("Dot and length")
	{
		Vec2 vec1(2, 2);
		Vec2 vec2(5, 5);

		CHECK(vec1.Dot(vec2) == 20);
		CHECK(Vec2::Dot(vec1, vec2) == 20);

		CHECK(vec1.Length() == sqrt(8.0f));
		CHECK(vec2.LengthSquared() == 50);
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
	}

	SECTION("Dot, cross and length")
	{
        Vec3 vec1(1, 2, 3);
        Vec3 vec2(7, 8, 9);

        CHECK(vec1.Dot(vec2) == 50);
        CHECK(Vec3::Dot(vec2, vec1) == 50);

        CHECK(vec1.Length() == sqrt(14.0f));
        CHECK(vec2.LengthSquared() == 194);

        CHECK(vec1.Cross(vec2) == Vec3(-6, 12, -6));
        CHECK(Vec3::Cross(vec2, vec1) == Vec3(6, -12, 6));
	}
}

TEST_CASE("Vector4 tests", "[vector]")
{
	SECTION("Boolean tests")
	{

	}

	SECTION("Basic operators")
	{

	}

	SECTION("Dot and length")
	{

	}
}