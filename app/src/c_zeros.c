#include <stdint.h>


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
