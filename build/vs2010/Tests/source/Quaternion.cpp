#include <catch.hpp>

#include <pmath/Quaternion.hpp>

using namespace pmath;

TEST_CASE("Quaternion tests", "[quaternion]")
{
    SECTION("Operators")
    {
        CHECK(Quat() == Quat::identity);
        CHECK(Quat(1,2,3,4) != Quat::identity);
        CHECK_FALSE(Quat(1,2,3,4) == Quat::identity);
        CHECK_FALSE(Quat(1,2,3,4) != Quat(1,2,3,4));

        CHECK((Quat() - Quat(1,0,0,0)) == Quat(0,0,0,0));
        CHECK((Quat(1,2,3,4) - Quat(1,2,3,4)) == Quat(0,0,0,0));
        CHECK((Quat(1,2,3,4) - Quat(1,2,3,4)) == Quat(0,0,0,0));
        CHECK(-Quat(1,2,3,4) == Quat(-1,-2,-3,-4));
        CHECK((Quat(1,2,3,4) * 2) == Quat(2,4,6,8));
        CHECK((Quat(1,2,3,4) *= 2) == Quat(2,4,6,8));
        CHECK((Quat(1,2,3,4) / 2) == Quat(.5f,1,1.5f,2));
        CHECK((Quat(1,2,3,4) /= 2) == Quat(.5f,1,1.5f,2));

        Quat q;
        CHECK((q += Quat(1,2,3,4)) == Quat(2, 2, 3, 4));
        CHECK((q -= Quat(1,2,3,4)) == Quat());
        CHECK((q = Quat(4,3,2,1)) == Quat(4,3,2,1));
        CHECK((q * Quat(1,2,3,4)) == Quat(-12, 16, 4, 22));
        CHECK((q *= Quat(1,2,3,4)) == Quat(-12, 16, 4, 22));
    }

    SECTION("Inverse, conjugate etc...")
    {
        Quat q(1,2,3,4);

        CHECK(q.conjugate() == Quat(1, -2, -3, -4));
        CHECK(q.inverse() == Quat(1.f/30.f, -1.f/15.f, -1.f/10.f, -2.f/15.f));
    }

    SECTION("Normal and length")
    {
        Quat q(1,2,3,4);

        CHECK(q.unitQuaternion() == Quat(1/sqrt(30.f), sqrt(2/15.f),
            sqrt(3/10.f), 2*sqrt(2/15.f)));
    }

    SECTION("Rotations")
    {
        CHECK((Vec3(1, 0, 0) * Quat::createRotationZ(90)) == Vec3(0, 1, 0));
        CHECK((Vec3(1, 0, 0) * Quat::createRotationY(90)) == Vec3(0, 0, -1));
        CHECK((Vec3(0, 0, 1) * Quat::createRotationX(90)) == Vec3(0, -1, 0));
        Vec3 vec(1, 0, 0);
        CHECK((vec *= Quat::createRotationZ(90)) == Vec3(0, 1, 0));

        CHECK((Vec3(0, 1, 0) * Quat::createRotation(Vec3(0, 0, 1), 180)) ==  Vec3(0, -1, 0));
        const auto q1 = Quat::createRotation(Vec3(1,1,1), 45);
        const auto q2 = Quat::createRotation(Vec3(1,1,1), 60);
        const auto q3 = Quat::createRotation(Vec3(1,0,1), 75);

        const auto q4 = q3 * q2 * q1;
        CHECK(q4.isUnitQuaternion());
        std::cout << q4 << std::endl;
    }
}