#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_GT(1, 2);

    /* this one will fail */
    BDUT_ASSERT_GT(1, 1);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

