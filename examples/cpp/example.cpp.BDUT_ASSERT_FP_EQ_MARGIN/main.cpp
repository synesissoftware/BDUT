#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    double const actual_near = 3.0001;
    double const actual_far = 3.01;

    BDUT_ASSERT_FP_EQ_MARGIN(3.0, 3.0, 0.0001);
    BDUT_ASSERT_FP_EQ_MARGIN(3.0, actual_near, 0.0001);
    BDUT_ASSERT_FP_EQ_MARGIN_MSG(3.0, actual_near, 0.0001, "match");

    /* this one will fail */
    BDUT_ASSERT_FP_EQ_MARGIN_MSG(3.0, actual_far, 0.0001, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
