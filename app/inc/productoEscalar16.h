#pragma once

#include "profiling.h"


void        test_productoEscalar16  (struct profiling_t *pr);
void        c_productoEscalar16     (uint16_t * vectorIn, uint16_t * vectorOut,
                                     uint32_t longitud, uint16_t escalar);
extern void s_productoEscalar16     (uint16_t * vectorIn, uint16_t * vectorOut,
                                     uint32_t longitud, uint16_t escalar);
