#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    int const actual0 = 0;
    int const actual1 = 1;

    BDUT_ASSERT_TRUE(1);
    BDUT_ASSERT_TRUE(actual1);
    BDUT_ASSERT_TRUE_MSG(actual1, "match");

    /* this one will fail */
    BDUT_ASSERT_TRUE_MSG(actual0, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

