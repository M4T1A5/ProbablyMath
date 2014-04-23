#include <catch.hpp>

#include <PMath/Vector2.hpp>

using namespace pmath;

TEST_CASE("Vector2 tests", "[vector]")
{
	SECTION("Boolean tests")
	{
		REQUIRE(Vec2(1, 1) != Vec2(2, 1));
		REQUIRE(Vec2(2, 2) == Vec2(2, 2));
		REQUIRE_FALSE(Vec2(2, 2) == Vec2(1, 2));
		REQUIRE_FALSE(Vec2(2, 2) != Vec2(2, 2));
	}

	SECTION("Basic operators")
	{
		Vec2 vec1(5, 10);
		Vec2 vec2(2, 4);

		REQUIRE((vec1 - vec2) == Vec2(3, 6));
		REQUIRE((vec1 + vec2) == Vec2(7, 14));
		REQUIRE((vec1 * 2) == Vec2(10, 20));
		REQUIRE((vec2 / 2) == Vec2(1, 2));
		

		vec1 *= 2;
		REQUIRE(vec1 == Vec2(10, 20));
		vec2 /= 2;
		REQUIRE(vec2 == Vec2(1, 2));


		vec1 = Vec2(5, 10);
		vec2 = Vec2(2, 4);
		REQUIRE(vec1 == Vec2(5, 10));
		REQUIRE(vec2 == Vec2(2, 4));

		vec1 += Vec2(5, 5);
		vec2 -= Vec2(2, 4);
		REQUIRE(vec1 == Vec2(10, 15));
		REQUIRE(vec2 == Vec2());
	}

	SECTION("Dot and Length")
	{
		Vec2 vec1(2, 2);
		Vec2 vec2(5, 5);

		REQUIRE(vec1.Dot(vec2) == 20);
		REQUIRE(Vec2::Dot(vec1, vec2) == 20);

		REQUIRE(vec1.Length() == sqrt(8.0f));
		REQUIRE(vec2.LengthSquared() == 50);
	}
}