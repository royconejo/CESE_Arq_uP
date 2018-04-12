#pragma once

#include "profiling.h"


void        test_eco    (struct profiling_t *pr);
void        c_eco       (uint16_t * vectorIn, uint16_t * vectorOut);
extern void s_eco       (uint16_t * vectorIn, uint16_t * vectorOut);
