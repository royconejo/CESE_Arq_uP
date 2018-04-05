#pragma once

#include "cmsis.h"

#define PROFILE_FUNCTION(pr,l,f,...) \
    DWT->CYCCNT = 0; \
    l##_##f (__VA_ARGS__); \
    pr-> l .cycles = DWT->CYCCNT;


struct profiling_t
{
    uint32_t    functionCalls;
    uint32_t    iterations;

    struct
    {
       uint32_t cycles;
       uint32_t ns;
    } c;

    struct
    {
       uint32_t cycles;
       uint32_t ns;
    } s;
};


void profilingInit      ();
void profilingStart     (uint32_t functionCalls, uint32_t iterations, struct profiling_t *pr);
void profilingDone      (struct profiling_t *pr);
