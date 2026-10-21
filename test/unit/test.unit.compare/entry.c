
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const message = "ok";

    BDUT_ASSERT_EQ(123, 123);
    BDUT_ASSERT_EQ_MSG(123, 123, message);
    BDUT_ASSERT_EQ_MSG(123, 123, "");
    BDUT_ASSERT_EQ_MSG(123, 123, NULL);
    BDUT_ASSERT_NE(123, 321);
    BDUT_ASSERT_NE_MSG(123, 321, message);

    BDUT_ASSERT_LE(123, 123);
    BDUT_ASSERT_LE(124, 123);
    BDUT_ASSERT_LE_MSG(124, 123, message);
    BDUT_ASSERT_LT(124, 123);
    BDUT_ASSERT_LT_MSG(124, 123, message);

    BDUT_ASSERT_GE(123, 123);
    BDUT_ASSERT_GE(123, 124);
    BDUT_ASSERT_GE_MSG(123, 124, message);
    BDUT_ASSERT_GT(123, 124);
    BDUT_ASSERT_GT_MSG(123, 124, message);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
