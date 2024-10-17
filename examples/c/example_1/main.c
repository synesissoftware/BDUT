
#include <bdut/bdut.h>

#include <stdio.h>

int main(int argc, char* argv[])
{
    BDUT_ASSERT_EQ(1, 2);

    fprintf(stdout, "%s: ALL TESTS PASSED\n", argv[0]);

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

