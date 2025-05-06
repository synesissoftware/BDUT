
#include <bdut/bdut.h>

#include <stdio.h>


int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    BDUT_ASSERT_LE(1, 2);
    BDUT_ASSERT_LE(-1, 1);

    /* this one will fail */
    BDUT_ASSERT_LE(-1, -2);


    fprintf(stdout, "%s: ALL TESTS PASSED\n", argv[0]);

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

