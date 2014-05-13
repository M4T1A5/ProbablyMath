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

        Quat q2(4, 3, 2, 1);
        CHECK(q.dot(q2) == 20);
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
        auto q1 = Quat::createRotation(Vec3(1,1,1), 45);

        CHECK(q1.isUnitQuaternion());

        auto q2 = Quat::createRotationZ(90);
        CHECK(q2.toMatrix3() == Mat3(0, -1, 0,
                                     1, 0, 0,
                                     0, 0, 1));

        CHECK(q2.toMatrix4() == Mat4(Mat3(0, -1, 0,
                                          1, 0, 0,
                                          0, 0, 1)));

        Mat3 rotationZ90(cos<float>(90), -sin<float>(90), 0,
                         sin<float>(90), cos<float>(90), 0,
                         0, 0, 1);
        Mat4 rz90 = Mat4(rotationZ90);
        CHECK(Quat(rotationZ90) == Quat::createRotationZ(90));
        CHECK(Quat(rz90) == Quat::createRotationZ(90));
        CHECK(Quat(q2.toMatrix3()) == Quat::createRotationZ(90));

        q1 = Quat::createRotationZ(0);
        q2 = Quat::createRotationZ(90);
        CHECK(Quat::slerp(q1, q2, 0.5f) == Quat::createRotationZ(45));
    }
}