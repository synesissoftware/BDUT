#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_LT(2, 1);

    /* this one will fail */
    BDUT_ASSERT_LT(1, 1);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

