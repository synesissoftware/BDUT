
#include <bdut/bdut.h>

#include <stdio.h>


int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    BDUT_ASSERT_TRUE(1);
    BDUT_ASSERT_TRUE(!0);

    /* this one will fail */
    BDUT_ASSERT_TRUE(0);


    fprintf(stdout, "%s: ALL TESTS PASSED\n", argv[0]);

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

