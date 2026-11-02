
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const message = "ok";

    BDUT_ASSERT_TRUE(1);
    BDUT_ASSERT_TRUE(!0);
    BDUT_ASSERT_TRUE(42);
    BDUT_ASSERT_TRUE_MSG(1, message);
    BDUT_ASSERT_TRUE_MSG(1, "");
    BDUT_ASSERT_TRUE_MSG(1, NULL);

    BDUT_ASSERT_FALSE(0);
    BDUT_ASSERT_FALSE(!1);
    BDUT_ASSERT_FALSE(0 == 1);
    BDUT_ASSERT_FALSE_MSG(0, message);
    BDUT_ASSERT_FALSE_MSG(0, "");
    BDUT_ASSERT_FALSE_MSG(0, NULL);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
