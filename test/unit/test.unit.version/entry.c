
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    {
        BDUT_ASSERT_EQ(0, BDUT_VER_MAJOR);
        BDUT_ASSERT_NE(1, BDUT_VER_MAJOR);

        BDUT_ASSERT_LT(1, BDUT_VER_MAJOR);
        BDUT_ASSERT_LE(0, BDUT_VER_MAJOR);

        BDUT_ASSERT_GE(0, BDUT_VER_MAJOR);
    }

    {
        BDUT_ASSERT_NE(2, BDUT_VER_MINOR);
        BDUT_ASSERT_NE(3, BDUT_VER_MINOR);
        BDUT_ASSERT_EQ(4, BDUT_VER_MINOR);
        BDUT_ASSERT_NE(5, BDUT_VER_MINOR);

        BDUT_ASSERT_LT(5, BDUT_VER_MINOR);
        BDUT_ASSERT_LE(4, BDUT_VER_MINOR);

        BDUT_ASSERT_GT(3, BDUT_VER_MINOR);
        BDUT_ASSERT_GE(4, BDUT_VER_MINOR);
    }

    {
        BDUT_ASSERT_EQ(0, BDUT_VER_PATCH);
        BDUT_ASSERT_NE(1, BDUT_VER_PATCH);
        BDUT_ASSERT_NE(2, BDUT_VER_PATCH);

        BDUT_ASSERT_LT(1, BDUT_VER_PATCH);
        BDUT_ASSERT_LE(0, BDUT_VER_PATCH);

        BDUT_ASSERT_GE(0, BDUT_VER_PATCH);
    }

    {
        BDUT_ASSERT_GE(0x41, BDUT_VER_ALPHABETA);

        BDUT_ASSERT_LE(0xFF, BDUT_VER_ALPHABETA);
    }

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

