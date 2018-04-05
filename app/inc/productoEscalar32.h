#pragma once

#include "profiling.h"


void        test_productoEscalar32  (struct profiling_t *pr);
void        c_productoEscalar32     (uint32_t * vectorIn, uint32_t * vectorOut,
                                     uint32_t longitud, uint32_t escalar);
extern void s_productoEscalar32     (uint32_t * vectorIn, uint32_t * vectorOut,
                                     uint32_t longitud, uint32_t escalar);
