
#include <bdut/bdut.h>

#include <stdio.h>


int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    {
        BDUT_ASSERT_EQ(0, BDUT_VER_MAJOR);
        BDUT_ASSERT_NE(1, BDUT_VER_MAJOR);

        BDUT_ASSERT_LT(1, BDUT_VER_MAJOR);
        BDUT_ASSERT_LE(0, BDUT_VER_MAJOR);

        BDUT_ASSERT_GE(0, BDUT_VER_MAJOR);
    }

    {
        BDUT_ASSERT_NE(2, BDUT_VER_MINOR);
        BDUT_ASSERT_EQ(3, BDUT_VER_MINOR);
        BDUT_ASSERT_NE(4, BDUT_VER_MINOR);

        BDUT_ASSERT_LT(4, BDUT_VER_MINOR);
        BDUT_ASSERT_LE(3, BDUT_VER_MINOR);

        BDUT_ASSERT_GT(2, BDUT_VER_MINOR);
        BDUT_ASSERT_GE(3, BDUT_VER_MINOR);
    }

    {
        BDUT_ASSERT_NE(2, BDUT_VER_PATCH);
        BDUT_ASSERT_EQ(3, BDUT_VER_PATCH);
        BDUT_ASSERT_NE(4, BDUT_VER_PATCH);

        BDUT_ASSERT_LT(4, BDUT_VER_PATCH);
        BDUT_ASSERT_LE(3, BDUT_VER_PATCH);

        BDUT_ASSERT_GT(2, BDUT_VER_PATCH);
        BDUT_ASSERT_GE(3, BDUT_VER_PATCH);
    }

    {
        BDUT_ASSERT_GE(0x41, BDUT_VER_ALPHABETA);

        BDUT_ASSERT_LE(0xFF, BDUT_VER_ALPHABETA);
    }

    fprintf(stdout, "%s: ALL TESTS PASSED\n", argv[0]);

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

