#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const actual_abc = "abc";
    char const* const actual_abd = "abd";

    BDUT_ASSERT_STRING_EQUAL("abc", "abc");
    BDUT_ASSERT_STRING_EQUAL("abc", actual_abc);
    BDUT_ASSERT_STRING_EQUAL_MSG("abc", actual_abc, "match");

    /* this one will fail */
    BDUT_ASSERT_STRING_EQUAL_MSG("abc", actual_abd, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
