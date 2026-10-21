#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    BDUT_ASSERT_EQ(1, 1);

    /* this one will fail */
    BDUT_ASSERT_EQ(1, 2);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

