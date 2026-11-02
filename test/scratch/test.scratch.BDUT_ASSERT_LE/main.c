
#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_LE(2, 1);
    BDUT_ASSERT_LE(1, -1);
    BDUT_ASSERT_LE_MSG(1, -1, "match");

    /* this one will fail */
    BDUT_ASSERT_LE_MSG(-2, -1, "intentional failure");


    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

