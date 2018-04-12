#pragma once

#include "profiling.h"


void        test_correlacionCruzada (struct profiling_t *pr);
void        c_correlacionCruzada    (uint16_t * vectorIn, uint16_t * vectorOut,
                                     uint32_t longitudVectorIn);
extern void s_correlacionCruzada    (uint16_t * vectorIn, uint16_t * vectorOut,
                                     uint32_t longitudVectorIn);
