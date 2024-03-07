
#include <bdut/bdut.h>

#include <stdio.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_STRING_CONTAINS("", "abcdefghijklmnopqrstuvwxyz");
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdefghijklmnopqrstuvwxyz");

    /* this one will fail */
    BDUT_ASSERT_STRING_CONTAINS("abd", "abcdefghijklmnopqrstuvwxyz");


    fprintf(stdout, "%s: ALL TESTS PASSED\n", argv[0]);

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

