#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    int const actual1 = 1;
    int const actual2 = 2;

    BDUT_ASSERT_LE(1, 1);
    BDUT_ASSERT_LE(2, actual1);
    BDUT_ASSERT_LE_MSG(2, actual1, "match");

    /* this one will fail */
    BDUT_ASSERT_LE_MSG(1, actual2, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

