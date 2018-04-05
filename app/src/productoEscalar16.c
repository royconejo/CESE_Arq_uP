#include "productoEscalar16.h"


#define VEC_SIZE        100
static const uint16_t   escalar = 5;
static uint16_t         vin     [VEC_SIZE];
static uint16_t         vout    [VEC_SIZE];


/*
    3)  Adapte la función del ejercicio 2 para realizar operaciones sobre
        vectores de 16 bits:

        void productoEscalar16 (uint16_t * vectorIn, uint16_t * vectorOut,
                                uint32_t longitud, uint16_t escalar);
*/


void c_productoEscalar16 (uint16_t * vectorIn, uint16_t * vectorOut,
                          uint32_t longitud, uint16_t escalar)
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


void test_productoEscalar16 (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    test_reset ();
    PROFILE_FUNCTION(pr, c, productoEscalar16, vin, vout, VEC_SIZE, escalar)
    test_reset ();
    PROFILE_FUNCTION(pr, s, productoEscalar16, vin, vout, VEC_SIZE, escalar)

    profilingDone (pr);
}

