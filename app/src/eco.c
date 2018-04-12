#include "eco.h"


#define VEC_SIZE    4096
static uint16_t     vin     [VEC_SIZE];
static uint16_t     vout    [VEC_SIZE];


/*
    10) Realizar una función que recibe un vector de 4096 valores de 16 bits
        (signados), que corresponden a muestras de audio tomadas a una tasa de
        muestreo de 44.100 muestras/s. La función debe introducir un “eco” de la
        mitad de la amplitud de la muestra original a los 20ms de comenzada la
        grabación.

        Nota: El eco consiste en adicionar a la señal original, la propia señal
        original dividida por dos y atrasada en 20ms.

        Variante: Una vez implementada la función, programar una nueva versión
        que utilice las instrucciones SIMD para optimizar la ejecución del
        algoritmo.
*/


// NOTA: Los vectores tienen un tamaño fijo de 4096!
void c_eco (uint16_t * vectorIn, uint16_t * vectorOut)
{
    if (!vectorIn || !vectorOut)
    {
        return;
    }

    uint32_t echo = 882;

    for (uint32_t i = 0; i < echo; ++i)
    {
        vectorOut[i] = vectorIn[i];
    }

    while (echo < 4096)
    {
        for (uint32_t i = 0; echo + i < 4096; ++i)
        {
            vectorOut[echo + i] = vectorOut[echo + i] + (vectorIn[i] >> 1);
        }
        echo += 882;
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


void test_eco (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    test_reset ();
    PROFILE_FUNCTION(pr, c, eco, vin, vout)
    test_reset ();
    PROFILE_FUNCTION(pr, s, eco, vin, vout)

    profilingDone (pr);
}

