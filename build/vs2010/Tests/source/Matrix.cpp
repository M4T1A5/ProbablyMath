#include <catch.hpp>

#include <pmath/Matrix.hpp>

using namespace pmath;

TEST_CASE("Matrix2 tests", "[matrix]")
{
    REQUIRE(Mat2::identity == Mat2());

    SECTION("Determinant")
    {
        Mat2 mat1(1, 2, 3, 4);
        CHECK(mat1.determinant() == -2.f);
    }

    SECTION("Boolean tests")
    {
        Mat2 mat1(1, 2, 3, 4), mat2(5, 2, 7, 6);
        CHECK(mat1 != mat2);
        CHECK_FALSE(mat1 != mat1);
        CHECK(mat1 == mat1);
        CHECK_FALSE(mat1 == mat2);
    }

    SECTION("Basic operators")
    {
        Mat2 mat1(1, 2, 3, 4), mat2(4, 3, 2, 1);

        std::cout << mat1 << std::endl;
        
        CHECK((mat1 - mat1) == Mat2(0, 0, 0, 0));
        CHECK((mat1 - mat2) == Mat2(-3, -1, 1, 3));

        CHECK((mat1 * mat2) == Mat2(8, 5, 20, 13));
        Mat2 mat3 = mat1;
        CHECK((mat3 *= mat2) == Mat2(8, 5, 20, 13));

        CHECK((mat1 * Vec2(1, 2)) == Vec2(5, 11));
        CHECK((mat2 * Vec2(8, 9)) == Vec2(59, 25));

        mat3 = Mat2();
        CHECK((mat3 += mat1) == (Mat2() + mat1));
        mat3 = Mat2();
        CHECK((mat3 -= mat1) == (Mat2() - mat1));
        CHECK((mat1 * 2) == Mat2(2, 4, 6, 8));
        CHECK((mat1 / 2) == Mat2(.5f, 1, 1.5f, 2));
    }

    SECTION("Inverse, transpose")
    {
        Mat2 mat(1, 2, 3, 4);
        CHECK(mat.inverse() == (0.5f*Mat2(-4, 2, 3, -1)));

        CHECK(mat.transpose() == Mat2(1, 3, 2, 4));
    }
}


TEST_CASE("Matrix3 tests", "[matrix]")
{

}


TEST_CASE("Matrix4 tests", "[matrix]")
{

}