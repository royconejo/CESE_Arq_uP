#pragma once

#include "profiling.h"


void        test_ajustarBrillo      (struct profiling_t *pr);
void        c_ajustarBrillo         (uint8_t *imagen, uint32_t ancho,
                                     uint32_t alto, int8_t brillo);
extern void s_ajustarBrillo         (uint8_t *imagen, uint32_t ancho,
                                     uint32_t alto, int8_t brillo);
