
#include <bdut/bdut.h>

#include <iostream>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_STRING_CONTAINS("", "abcdefghijklmnopqrstuvwxyz");
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdefghijklmnopqrstuvwxyz");

    /* this one will fail */
    BDUT_ASSERT_STRING_CONTAINS("abd", "abcdefghijklmnopqrstuvwxyz");


    std::cout << argv[0] << ": ALL TESTS PASSED" << std::endl;

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

