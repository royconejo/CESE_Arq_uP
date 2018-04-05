#pragma once

#include "profiling.h"


void        test_filtroVentana10    (struct profiling_t *pr);
void        c_filtroVentana10       (uint16_t * vectorIn, uint16_t * vectorOut,
                                     uint32_t longitudVectorIn);
extern void s_filtroVentana10       (uint16_t * vectorIn, uint16_t * vectorOut,
                                     uint32_t longitudVectorIn);
