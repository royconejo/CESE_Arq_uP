#include "productoEscalar12.h"


#define VEC_SIZE        100
static const uint16_t   escalar = 5;
static uint16_t         vin     [VEC_SIZE];
static uint16_t         vout    [VEC_SIZE];


/*
    4)  Adapte la función del ejercicio 3 para saturar el resultado del producto
        a 12 bits:

        void productoEscalar12 (uint16_t * vectorIn, uint16_t * vectorOut,
                                uint32_t longitud, uint16_t escalar);
*/


void c_productoEscalar12 (uint16_t * vectorIn, uint16_t * vectorOut,
                          uint32_t longitud, uint16_t escalar)
{
    if (!vectorIn || !vectorOut || !longitud)
    {
        return;
    }

    while (-- longitud)
    {
        uint16_t sat = *vectorIn++ * escalar;
        if (sat > (1 << 11))
        {
            sat = (1 << 11);
        }

        *vectorOut++ = sat;
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


void test_productoEscalar12 (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    test_reset ();
    PROFILE_FUNCTION(pr, c, productoEscalar12, vin, vout, VEC_SIZE, escalar)
    test_reset ();
    PROFILE_FUNCTION(pr, s, productoEscalar12, vin, vout, VEC_SIZE, escalar)

    profilingDone (pr);
}

