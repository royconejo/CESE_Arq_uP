#include "zeros.h"


#define VEC_SIZE    1000
static uint32_t     vec[VEC_SIZE];


/*
    1)  Realizar una función que inicialice un vector con ceros. La función debe
        tener el siguiente prototipo:

        void zeros (uint32_t * vector, uint32_t longitud);
*/


void c_zeros (uint32_t * vector, uint32_t longitud)
{
    if (!vector || !longitud)
    {
        return;
    }

    uint32_t loop1 = longitud & 0x7;
    uint32_t loop8 = longitud - loop1;

    while (loop8)
    {
        vector[0] = 0;
        vector[1] = 0;
        vector[2] = 0;
        vector[3] = 0;
        vector[4] = 0;
        vector[5] = 0;
        vector[6] = 0;
        vector[7] = 0;
        vector += 8;
        loop8 -= 8;
    }

    while (loop1 --)
    {
        *vector ++ = 0;
    }
}


#if 0
void c_zeros (uint32_t * vector, uint32_t longitud)
{
    if (!vector || !longitud)
    {
        return;
    }

    while (longitud --)
    {
        *vector ++ = 0;
    }
}
#endif


static void test_reset ()
{
    for (uint32_t i = 0; i < VEC_SIZE; ++i)
    {
        vec[i] = 0xCACA0000 | (((i+1) & 0xFFFF));
    }
}


void test_zeros (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    test_reset ();
    PROFILE_FUNCTION(pr, c, zeros, vec, VEC_SIZE)
    test_reset ();
    PROFILE_FUNCTION(pr, s, zeros, vec, VEC_SIZE)

    profilingDone (pr);
}

