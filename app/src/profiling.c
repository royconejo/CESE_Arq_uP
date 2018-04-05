#include "profiling.h"
#include "chip.h"   // SystemCoreClock


static uint32_t profilingOverhead = 0;


static void measureOverhead (struct profiling_t *pr)
{
    pr->c.cycles = DWT->CYCCNT;
}


void profilingInit ()
{
    DWT->CTRL |= 1 << DWT_CTRL_CYCCNTENA_Pos;

    struct profiling_t pr;
    pr.c.cycles     = 0;
    DWT->CYCCNT     = 0;
    measureOverhead (&pr);

    profilingOverhead = pr.c.cycles;
}


void profilingStart (uint32_t functionCalls, uint32_t iterations, struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    pr->functionCalls   = functionCalls;
    pr->iterations      = iterations;
}


void profilingDone (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    // TODO: tener en cuenta pr->functionCalls e iterations

    if (pr->c.cycles >= profilingOverhead)
    {
        pr->c.cycles -= profilingOverhead;
    }

    if (pr->s.cycles >= profilingOverhead)
    {
        pr->s.cycles -= profilingOverhead;
    }

    pr->c.ns = (uint32_t) (((double)pr->c.cycles / (double)SystemCoreClock) * 1000000000.0);
    pr->s.ns = (uint32_t) (((double)pr->s.cycles / (double)SystemCoreClock) * 1000000000.0);
}
