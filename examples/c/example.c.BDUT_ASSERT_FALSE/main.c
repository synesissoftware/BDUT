#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    int const actual0 = 0;
    int const actual1 = 1;

    BDUT_ASSERT_FALSE(0);
    BDUT_ASSERT_FALSE(actual0);

    /* this one will fail */
    BDUT_ASSERT_FALSE(actual1);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

