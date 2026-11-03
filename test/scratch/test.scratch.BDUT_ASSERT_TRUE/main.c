
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_TRUE(1);
    BDUT_ASSERT_TRUE(!0);
    BDUT_ASSERT_TRUE_MSG(1, "match");

    BDUT_ASSERT_FALSE(!1);
    BDUT_ASSERT_FALSE(0);
    BDUT_ASSERT_FALSE_MSG(0, "match");

    /* this one will fail */
    BDUT_ASSERT_TRUE_MSG(0, "intentional failure");


    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

