#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const actual_abc = "abc";
    char const* const actual_abd = "abd";

    BDUT_ASSERT_STRING_EQUAL_N("abc", "abd", 2);
    BDUT_ASSERT_STRING_EQUAL_N("abc", actual_abd, 2);
    BDUT_ASSERT_STRING_EQUAL_N_MSG("abc", actual_abc, 3, "match");

    /* this one will fail */
    BDUT_ASSERT_STRING_EQUAL_N_MSG("abc", actual_abd, 3, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
