#include <catch.hpp>

#include <pmath/Matrix.hpp>

using namespace pmath;

// Matrix2
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


		Vec2 vec1(1,2), vec2(8,9);
        CHECK((mat1 * vec1) == Vec2(5, 11));
        CHECK((mat2 * vec2) == Vec2(59, 25));

        mat3 = Mat2();
        CHECK((mat3 += mat1) == (Mat2() + mat1));
        mat3 = Mat2();
        CHECK((mat3 -= mat1) == (Mat2() - mat1));
        CHECK((mat1 * 2) == Mat2(2, 4, 6, 8));
        CHECK((mat1 / 2) == Mat2(.5f, 1, 1.5f, 2));
		CHECK(Mat2i(Mat2(1, 2)) == Mat2i(1, 2));
    }

    SECTION("Inverse, transpose")
    {
        Mat2 mat(1, 2, 3, 4);
        CHECK(mat.inverse() == (0.5f*Mat2(-4, 2, 3, -1)));

        CHECK(mat.transpose() == Mat2(1, 3, 2, 4));
    }
}


// Matrix 3
TEST_CASE("Matrix3 tests", "[matrix]")
{
    REQUIRE(Mat3::identity == Mat3());

    SECTION("Determinant")
    {
        Mat3 mat1(1, 2, 3, 4, 5, 6, 7, 8, 9);
        CHECK(mat1.determinant() == 0);
    }

    SECTION("Boolean tests")
    {
        Mat3 mat1(1, 2, 3, 4, 5, 6, 7, 8, 9), mat2(5, 2, 7, 6, 3, 7, 9, 2, 4);
        CHECK(mat1 != mat2);
        CHECK_FALSE(mat1 != mat1);
        CHECK(mat1 == mat1);
        CHECK_FALSE(mat1 == mat2);
    }

    SECTION("Basic operators")
    {
        Mat3 mat1(1, 2, 3, 4, 5, 6, 7, 8, 9), mat2(9, 8, 7, 6, 5, 4, 3, 2, 1);

        std::cout << mat1 << std::endl;
        
        CHECK((mat1 - mat1) == Mat3(0, 0, 0, 0, 0, 0, 0, 0, 0));
        CHECK((mat1 - mat2) == Mat3(-8, -6, -4, -2, 0, 2, 4, 6, 8));

        CHECK((mat1 * mat2) == (3.f*Mat3(10, 8, 6, 28, 23, 18, 46, 28, 30)));
        Mat3 mat3 = mat1;
        CHECK((mat3 *= mat2) == (3.f*Mat3(10, 8, 6, 28, 23, 18, 46, 28, 30)));


		Vec3 vec1(1,2,3), vec2(7,8,9);
        CHECK((mat1 * vec1) == Vec3(14, 32, 50));
        CHECK((mat2 * vec2) == Vec3(190, 118, 46));
        CHECK((mat2 * Vec2(4,5)) == Vec2(14, 47));

        CHECK((mat3 = Mat3()) == Mat3());
        CHECK((mat3 += mat1) == (Mat3() + mat1));
        mat3 = Mat3();
        CHECK((mat3 -= mat1) == (Mat3() - mat1));
        CHECK((mat1 * 2) == Mat3(2, 4, 6, 8, 10, 12, 14, 16, 18));
        CHECK((mat1 / 2) == Mat3(.5f, 1, 1.5f, 2, 2.5f, 3, 3.5f, 4, 4.5f));
		//CHECK(Mat3i(Mat3(1, 2)) == Mat3i(1, 2));
    }

    SECTION("Inverse, transpose")
    {
        Mat3 mat(2, 2, 3, 4, 5, 6, 7, 8, 9);
        CHECK(mat.inverse() == (1.f/3.f*Mat3(3, -6, 3, -6, 3, 0, 3, 2, -2)));

        CHECK(mat.transpose() == Mat3(2, 4, 7, 2, 5, 8, 3, 6, 9));
    }
}


// Matrix4
TEST_CASE("Matrix4 tests", "[matrix]")
{

}