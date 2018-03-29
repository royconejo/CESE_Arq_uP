#include "zeros.h"


#define VEC_SIZE    1000
static uint32_t     vec[VEC_SIZE];


static void testClear ()
{
    for (uint32_t i = 0; i < VEC_SIZE; ++i)
    {
        vec[i] = 0xCACAAAAA | ((i+1) & 0xFFFF);
    }
}


void testZeros (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    testClear ();
    PROFILE_FUNCTION(pr, c, zeros, vec, VEC_SIZE)
    testClear ();
    PROFILE_FUNCTION(pr, s, zeros, vec, VEC_SIZE)

    profilingDone (pr);
}

