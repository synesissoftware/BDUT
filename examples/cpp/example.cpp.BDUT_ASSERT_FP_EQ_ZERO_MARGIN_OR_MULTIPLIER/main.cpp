#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    double const actual_near = 123456.01;
    double const actual_far = 0.1;

    BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER(123456.0, 123456.0, 0.0001, 0.0001);
    BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER(123456.0, actual_near, 0.0001, 0.0001);
    BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER_MSG(0.0, 0.0, 0.0001, 0.0001, "match");

    /* this one will fail */
    BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER_MSG(0.0, actual_far, 0.0001, 0.0001, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
