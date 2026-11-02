#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    double const actual_near = 3.0000000005;
    double const actual_far = 3.01;

    BDUT_ASSERT_FP_EQ(3.0, 3.0);
    BDUT_ASSERT_FP_EQ(3.0, actual_near);
    BDUT_ASSERT_FP_EQ_MSG(3.0, actual_near, "match");

    /* this one will fail */
    BDUT_ASSERT_FP_EQ_MSG(3.0, actual_far, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
