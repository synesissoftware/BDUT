#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    int const actual0 = 0;
    int const actual1 = 1;

    BDUT_ASSERT_TRUE(1);
    BDUT_ASSERT_TRUE(actual1);

    /* this one will fail */
    BDUT_ASSERT_TRUE(actual0);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

