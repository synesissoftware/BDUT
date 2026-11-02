#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    char const* const message = "ok";
    int object1 = 1;
    int object2 = 2;
    int const* const actual1 = &object1;
    int const* const actual2 = &object2;
    void const* const actual_void = actual1;

    BDUT_ASSERT_PTR_EQ(NULL, NULL);
    BDUT_ASSERT_PTR_EQ(&object1, actual1);
    BDUT_ASSERT_PTR_EQ(actual1, actual_void);
    BDUT_ASSERT_PTR_EQ_MSG(&object1, actual1, message);
    BDUT_ASSERT_PTR_EQ_MSG(&object1, actual1, "");
    BDUT_ASSERT_PTR_EQ_MSG(&object1, actual1, NULL);

    BDUT_ASSERT_PTR_NE(NULL, &object1);
    BDUT_ASSERT_PTR_NE(&object1, actual2);
    BDUT_ASSERT_PTR_NE_MSG(&object1, actual2, message);
    BDUT_ASSERT_PTR_NE_MSG(&object1, actual2, "");
    BDUT_ASSERT_PTR_NE_MSG(&object1, actual2, NULL);

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
