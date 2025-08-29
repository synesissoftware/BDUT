
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_TRUE(1);
    BDUT_ASSERT_TRUE(!0);

    BDUT_ASSERT_FALSE(!1);
    BDUT_ASSERT_FALSE(0);

    /* this one will fail */
    BDUT_ASSERT_TRUE(0);


    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

