#include <stdint.h>


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
