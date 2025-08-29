
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_STRING_CONTAINS("", "abcdefghijklmnopqrstuvwxyz");
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdefghijklmnopqrstuvwxyz");

    /* this one will fail */
    BDUT_ASSERT_STRING_CONTAINS("abd", "abcdefghijklmnopqrstuvwxyz");


    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

