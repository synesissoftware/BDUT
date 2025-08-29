
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_EQ(123, 123);
    BDUT_ASSERT_NE(123, 321);

    BDUT_ASSERT_LE(123, 123);
    BDUT_ASSERT_LE(124, 123);
    BDUT_ASSERT_LT(124, 123);

    BDUT_ASSERT_GE(123, 123);
    BDUT_ASSERT_GE(123, 124);
    BDUT_ASSERT_GT(123, 124);

    BDUT_ASSERT_STRING_CONTAINS("", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abcdef", "abcdef");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

