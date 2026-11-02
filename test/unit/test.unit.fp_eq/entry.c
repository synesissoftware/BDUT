#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const message = "ok";
    double const actual_sum = 0.1 + 0.2;
    double const actual_near = 3.0001;
    double const actual_rel = 123456.01;
    double const actual_neg = -100.01;

    BDUT_ASSERT_FP_EQ(3.0, 3.0);
    BDUT_ASSERT_FP_EQ(0.3, actual_sum);
    BDUT_ASSERT_FP_EQ(0.0, 0.0);
    BDUT_ASSERT_FP_EQ_MSG(3.0, 3.0, message);
    BDUT_ASSERT_FP_EQ_MSG(3.0, 3.0, "");
    BDUT_ASSERT_FP_EQ_MSG(3.0, 3.0, NULL);

    BDUT_ASSERT_FP_EQ_MARGIN(3.0, actual_near, 0.0001);
    BDUT_ASSERT_FP_EQ_MARGIN(0.0, 0.05, 0.1);
    BDUT_ASSERT_FP_EQ_MARGIN_MSG(3.0, actual_near, 0.0001, message);
    BDUT_ASSERT_FP_EQ_MARGIN_MSG(3.0, actual_near, 0.0001, "");
    BDUT_ASSERT_FP_EQ_MARGIN_MSG(3.0, actual_near, 0.0001, NULL);

    BDUT_ASSERT_FP_EQ_MULTIPLIER(123456.0, actual_rel, 0.0001);
    BDUT_ASSERT_FP_EQ_MULTIPLIER(-100.0, actual_neg, 0.001);
    BDUT_ASSERT_FP_EQ_MULTIPLIER_MSG(123456.0, actual_rel, 0.0001, message);

    BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER(123456.0, actual_rel, 0.0001, 0.0001);
    BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER(0.0, 0.05, 0.0001, 0.1);
    BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER_MSG(0.0, 0.0, 0.0001, 0.0001, message);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
