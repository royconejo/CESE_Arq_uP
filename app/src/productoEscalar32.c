#include "productoEscalar32.h"


#define VEC_SIZE        100
static const uint32_t   escalar = 5;
static uint32_t         vin     [VEC_SIZE];
static uint32_t         vout    [VEC_SIZE];


/*
    2)  Realizar una función que realice el producto de un vector y un escalar
        (por ejemplo, podría servir para cambiar el nivel de amplitud de una
        señal).

        void productoEscalar32 (uint32_t * vectorIn, uint32_t * vectorOut,
                                uint32_t longitud, uint32_t escalar);
*/


void c_productoEscalar32 (uint32_t * vectorIn, uint32_t * vectorOut,
                          uint32_t longitud, uint32_t escalar)
{
    if (!vectorIn || !vectorOut || !longitud)
    {
        return;
    }

    while (-- longitud)
    {
        *vectorOut++ = *vectorIn++ * escalar;
    }
}


static void test_reset ()
{
    for (uint32_t i = 0; i < VEC_SIZE; ++i)
    {
        vin [i] = i;
        vout[i] = 0;
    }
}


void test_productoEscalar32 (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    test_reset ();
    PROFILE_FUNCTION(pr, c, productoEscalar32, vin, vout, VEC_SIZE, escalar)
    test_reset ();
    PROFILE_FUNCTION(pr, s, productoEscalar32, vin, vout, VEC_SIZE, escalar)

    profilingDone (pr);
}

