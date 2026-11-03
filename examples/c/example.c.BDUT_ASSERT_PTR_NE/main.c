#include <bdut/bdut.h>


int main(int argc, char* argv[])
{
    int object1 = 1;
    int object2 = 2;
    int const* const actual1 = &object1;
    int const* const actual2 = &object2;

    BDUT_ASSERT_PTR_NE(NULL, &object1);
    BDUT_ASSERT_PTR_NE(&object1, actual2);
    BDUT_ASSERT_PTR_NE_MSG(&object1, actual2, "match");

    /* this one will fail */
    BDUT_ASSERT_PTR_NE_MSG(&object1, actual1, "intentional failure");

    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */
