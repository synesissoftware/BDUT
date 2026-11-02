#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    int const actual1 = 1;

    BDUT_ASSERT_LT(2, 1);
    BDUT_ASSERT_LT(2, actual1);

    /* this one will fail */
    BDUT_ASSERT_LT(1, actual1);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
