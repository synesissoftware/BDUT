#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    int const actual0 = 0;
    int const actual1 = 1;

    BDUT_ASSERT_FALSE(0);
    BDUT_ASSERT_FALSE(actual0);
    BDUT_ASSERT_FALSE_MSG(actual0, "match");

    /* this one will fail */
    BDUT_ASSERT_FALSE_MSG(actual1, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

