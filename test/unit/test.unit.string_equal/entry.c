#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const message = "ok";
    char const* const actual_abc = "abc";
    char const* const actual_abd = "abd";

    BDUT_ASSERT_STRING_EQUAL("abc", "abc");
    BDUT_ASSERT_STRING_EQUAL("abc", actual_abc);
    BDUT_ASSERT_STRING_EQUAL("", "");
    BDUT_ASSERT_STRING_EQUAL(NULL, "");
    BDUT_ASSERT_STRING_EQUAL(NULL, NULL);
    BDUT_ASSERT_STRING_EQUAL_MSG("abc", actual_abc, message);
    BDUT_ASSERT_STRING_EQUAL_MSG("abc", actual_abc, "");
    BDUT_ASSERT_STRING_EQUAL_MSG("abc", actual_abc, NULL);

    BDUT_ASSERT_STRING_EQUAL_N("abc", "abd", 2);
    BDUT_ASSERT_STRING_EQUAL_N("abc", actual_abd, 2);
    BDUT_ASSERT_STRING_EQUAL_N("abc", "xyz", 0);
    BDUT_ASSERT_STRING_EQUAL_N("abc", actual_abc, 3);
    BDUT_ASSERT_STRING_EQUAL_N(NULL, "", 1);
    BDUT_ASSERT_STRING_EQUAL_N_MSG("abc", actual_abd, 2, message);
    BDUT_ASSERT_STRING_EQUAL_N_MSG("abc", actual_abd, 2, "");
    BDUT_ASSERT_STRING_EQUAL_N_MSG("abc", actual_abd, 2, NULL);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
