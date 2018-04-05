#include "filtroVentana10.h"


#define VEC_SIZE    100
static uint16_t     vin     [VEC_SIZE];
static uint16_t     vout    [VEC_SIZE];


/*
    5)  Realice una función que implemente un filtro de ventana móvil de 10
        valores sobre un vector de muestras.

        void filtroVentana10 (uint16_t * vectorIn, uint16_t * vectorOut,
                                uint32_t longitudVectorIn);
*/


void c_filtroVentana10 (uint16_t * vectorIn, uint16_t * vectorOut,
                        uint32_t longitudVectorIn)
{
    if (!vectorIn || !vectorOut || !longitudVectorIn || longitudVectorIn < 10)
    {
        return;
    }

    uint32_t ac = 0;

    ac += vectorIn[0];
    ac += vectorIn[1];
    ac += vectorIn[2];
    ac += vectorIn[3];
    ac += vectorIn[4];
    ac += vectorIn[5];
    ac += vectorIn[6];
    ac += vectorIn[7];
    ac += vectorIn[8];
    ac += vectorIn[9];

    longitudVectorIn -= 9;
    while (longitudVectorIn --)
    {
        *vectorOut ++ = (uint16_t) (ac / 10);
        ac -= vectorIn[0];
        ac += vectorIn[10];
        *vectorIn ++;
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


void test_filtroVentana10 (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    test_reset ();
    PROFILE_FUNCTION(pr, c, filtroVentana10, vin, vout, VEC_SIZE)
    test_reset ();
    PROFILE_FUNCTION(pr, s, filtroVentana10, vin, vout, VEC_SIZE)

    profilingDone (pr);
}

