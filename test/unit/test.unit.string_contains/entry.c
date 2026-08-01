
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_STRING_CONTAINS("", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("abcdef", "abcdef");
    BDUT_ASSERT_STRING_CONTAINS("bcd", "abcdef");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
