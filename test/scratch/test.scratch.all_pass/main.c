
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

    BDUT_ASSERT_STRING_CONTAINS("", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abcdef", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS_MSG("abc", "abcdef", message);
    BDUT_ASSERT_STRING_EQUAL("abc", "abc");
    BDUT_ASSERT_STRING_EQUAL_MSG("abc", "abc", message);
    BDUT_ASSERT_STRING_EQUAL_N("abc", "abd", 2);
    BDUT_ASSERT_STRING_EQUAL_N_MSG("abc", "abd", 2, message);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

