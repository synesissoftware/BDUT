#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const actual_abc = "abc";
    char const* const actual_abd = "abd";

    BDUT_ASSERT_STRING_CONTAINS("", "abcdefghijklmnopqrstuvwxyz");
    BDUT_ASSERT_STRING_CONTAINS(actual_abc, "abcdefghijklmnopqrstuvwxyz");

    /* this one will fail */
    BDUT_ASSERT_STRING_CONTAINS(actual_abd, "abcdefghijklmnopqrstuvwxyz");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

