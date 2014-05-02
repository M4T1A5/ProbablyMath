#include <catch.hpp>

#include  <Windows.h>

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

    SECTION("Operators")
    {
        Mat2 mat1(1, 2, 3, 4), mat2(4, 3, 2, 1);

        std::cout << mat1 << std::endl;
        
        CHECK((mat1 - mat1) == Mat2(0, 0, 0, 0));
        CHECK((mat1 - mat2) == Mat2(-3, -1, 1, 3));

        CHECK((mat1 * mat2) == Mat2(8, 5, 20, 13));


        Vec2 vec2(1,2);
        CHECK((mat1 * vec2) == Vec2(5, 11));
        CHECK((vec2 *= mat1) == Vec2(5, 11));

        Mat2 mat3(Vec2(1), Vec2(2));
        CHECK((mat3 = Mat2()) == Mat2());
        CHECK((mat3 += mat1) == (Mat2() + mat1));
        mat3 = Mat2();
        CHECK((mat3 -= mat1) == (Mat2() - mat1));
        CHECK((mat1 * 2) == Mat2(2, 4, 6, 8));
        CHECK((mat1 / 2) == Mat2(.5f, 1, 1.5f, 2));
        CHECK(Mat2i(Mat2(1, 2, 3, 4)) == Mat2i(1, 2, 3, 4));
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

    SECTION("Operators")
    {
        Mat3 mat1(1, 2, 3, 4, 5, 6, 7, 8, 9), mat2(9, 8, 7, 6, 5, 4, 3, 2, 1);

        std::cout << mat1 << std::endl;
        
        CHECK((mat1 - mat1) == Mat3(0, 0, 0, 0, 0, 0, 0, 0, 0));
        CHECK((mat1 - mat2) == Mat3(-8, -6, -4, -2, 0, 2, 4, 6, 8));

        CHECK((mat1 * mat2) == (3.f*Mat3(10, 8, 6, 28, 23, 18, 46, 38, 30)));

        Vec2 vec2(5, 8);
        Vec3 vec3(1,2,3);
        CHECK((mat1 * vec2) == Vec2(24, 66));
        CHECK((vec2 *= mat1) == Vec2(24, 66));
        CHECK((mat1 * vec3) == Vec3(14, 32, 50));
        CHECK((vec3 *= mat1) == Vec3(14, 32, 50));

        Mat3 mat3(Vec3(1), Vec3(2), Vec3(3));
        CHECK((mat3 = Mat3()) == Mat3());
        CHECK((mat3 += mat1) == (Mat3() + mat1));
        mat3 = Mat3();
        CHECK((mat3 -= mat1) == (Mat3() - mat1));
        CHECK((mat1 * 2) == Mat3(2, 4, 6, 8, 10, 12, 14, 16, 18));
        CHECK((mat1 / 2) == Mat3(.5f, 1, 1.5f, 2, 2.5f, 3, 3.5f, 4, 4.5f));
        CHECK(Mat3i(Mat3(Vec3(1), Vec3(2), Vec3(3))) 
            == Mat3i(Vec3(1), Vec3(2), Vec3(3)));
    }

    SECTION("Inverse, transpose, etc...")
    {
        Mat2 mat2(Vec2(1), Vec2(2));
        CHECK(Mat3(mat2) == Mat3(1,1,0, 2,2,0, 0,0,1));

        Mat3 mat(2, 2, 3, 4, 5, 6, 7, 8, 9);
        CHECK(mat.inverse() == (1.f/3.f*Mat3(3, -6, 3, -6, 3, 0, 3, 2, -2)));

        CHECK(mat.transpose() == Mat3(2, 4, 7, 2, 5, 8, 3, 6, 9));
    }
}


// Matrix4
TEST_CASE("Matrix4 tests", "[matrix]")
{
    REQUIRE(Mat4::identity == Mat4());

    SECTION("Determinant")
    {
        Mat4 mat1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
        CHECK(mat1.determinant() == 0);
    }

    SECTION("Boolean tests")
    {
        Mat4 mat1(1, 2, 3, 4,
                  5, 6, 7, 8,
                  9, 10, 11, 12,
                  13, 14, 15, 16);
        Mat4 mat2(5, 2, 7, 6,
                  3, 7, 9, 2,
                  4, 9, 2, 4,
                  9, 5, 8, 2);

        CHECK(mat1 != mat2);
        CHECK_FALSE(mat1 != mat1);
        CHECK(mat1 == mat1);
        CHECK_FALSE(mat1 == mat2);
    }

    SECTION("Operators")
    {
        Mat4 mat1(1, 2, 3, 4,
                  5, 6, 7, 8,
                  9, 10, 11, 12,
                  13, 14, 15, 16);

        Mat4 mat2(5, 2, 7, 6,
                  3, 7, 9, 2,
                  4, 9, 2, 4,
                  9, 5, 8, 2);

        std::cout << mat1 << std::endl;

        CHECK((mat1 - mat1) == Mat4(Vec4(0), Vec4(0), Vec4(0), Vec4(0)));
        CHECK((mat1 - mat2) == Mat4(-4, 0, -4, -2,
                                    2, -1, -2, 6,
                                    5, 1, 9, 8,
                                    4, 9, 7, 14));

        CHECK((mat1 * mat2) == Mat4(59, 63, 63, 30,
                                    143, 155, 167, 86,
                                    227, 247, 271, 142,
                                    311, 339, 375, 198));

        Vec2 vec2(5, 8);
        Vec3 vec3(7, 8, 9);
        Vec4 vec4(6, 4, 2, 6);
        CHECK((mat2 * vec2) == Vec2(47, 73));
        CHECK((vec2 *= mat2) == Vec2(47, 73));
        CHECK((mat2 * vec3) == Vec3(120, 160, 122));
        CHECK((vec3 *= mat2) == Vec3(120, 160, 122));
        CHECK((mat2 * vec4) == Vec4(88, 76, 88, 102));
        CHECK((vec4 *= mat2) == Vec4(88, 76, 88, 102));

        Mat4 mat3(Vec4(1), Vec4(2), Vec4(3), Vec4(4));
        CHECK((mat3 = Mat4()) == Mat4());
        CHECK((mat3 += mat1) == (Mat4() + mat1));
        mat3 = Mat4();
        CHECK((mat3 -= mat1) == (Mat4() - mat1));
        CHECK((mat1 * 2) == Mat4(2, 4, 6, 8,
                                 10, 12, 14, 16,
                                 18, 20, 22, 24,
                                 26, 28, 30, 32));
        CHECK((mat1 / 2) == Mat4(.5f, 1, 1.5f, 2,
                                 2.5f, 3, 3.5f, 4,
                                 4.5f, 5, 5.5f, 6,
                                 6.5f, 7, 7.5f, 8));
        CHECK(Mat4i(Mat4(Vec4(1), Vec4(2), Vec4(3), Vec4(4)))
            == Mat4i(Vec4(1), Vec4(2), Vec4(3), Vec4(4)));
    }

    SECTION("Inverse, transpose, etc..")
    {
        Mat3 mat3(Vec3(1), Vec3(2), Vec3(3));
        CHECK(Mat4(mat3) == Mat4(1,1,1,0,
                                 2,2,2,0,
                                 3,3,3,0,
                                 0,0,0,1));

        Mat4 mat(5, 2, 7, 6,
                  3, 7, 9, 2,
                  4, 9, 2, 4,
                  9, 5, 8, 2);

        CHECK(mat.inverse() == (1.f/2580.f * Mat4(-54, -330, 42, 408,
                                    -196, 140, 248, -48,
                                    68, 320, -244, -36, 
                                    461, -145, 167, -282)));

        CHECK(mat.transpose() == Mat4(5, 3, 4, 9,
                                      2, 7, 9, 5,
                                      7, 9, 2, 8,
                                      6, 2, 4, 2));
    }

    SECTION("Speed tests")
    {
        Mat4 mat(5, 2, 7, 6,
            3, 7, 9, 2,
            4, 9, 2, 4,
            9, 5, 8, 2);

        LARGE_INTEGER start, end;
        LARGE_INTEGER f;
        QueryPerformanceFrequency(&f);
        for (size_t i = 0; i < 5; ++i)
        {
            QueryPerformanceCounter(&start);
            for (size_t i = 0; i < 10000; ++i)
            {
                mat * mat;
            }
            QueryPerformanceCounter(&end);
            std::cout << "Elapsed time: " << double(end.QuadPart - start.QuadPart)/f.QuadPart << std::endl;
        }
    }
}