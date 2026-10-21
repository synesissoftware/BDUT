
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const message = "ok";

    BDUT_ASSERT_STRING_CONTAINS("", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abcdef", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("bcd", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS_MSG("abc", "abcdef", message);
    BDUT_ASSERT_STRING_CONTAINS_MSG("abc", "abcdef", "");
    BDUT_ASSERT_STRING_CONTAINS_MSG("abc", "abcdef", NULL);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
