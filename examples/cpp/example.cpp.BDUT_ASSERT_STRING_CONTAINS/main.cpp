#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const actual_abc = "abc";
    char const* const actual_abd = "abd";

    BDUT_ASSERT_STRING_CONTAINS("", "abcdefghijklmnopqrstuvwxyz");
    BDUT_ASSERT_STRING_CONTAINS(actual_abc, "abcdefghijklmnopqrstuvwxyz");
    BDUT_ASSERT_STRING_CONTAINS_MSG(actual_abc, "abcdefghijklmnopqrstuvwxyz", "match");

    /* this one will fail */
    BDUT_ASSERT_STRING_CONTAINS_MSG(actual_abd, "abcdefghijklmnopqrstuvwxyz", "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

