
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_TRUE(1);
    BDUT_ASSERT_TRUE(!0);
    BDUT_ASSERT_TRUE(42);

    BDUT_ASSERT_FALSE(0);
    BDUT_ASSERT_FALSE(!1);
    BDUT_ASSERT_FALSE(0 == 1);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
