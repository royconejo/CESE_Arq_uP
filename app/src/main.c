#include "board.h"
#include "profiling.h"
#include "zeros.h"


static void initHardware ()
{
	Board_Init();
	SystemCoreClockUpdate();
	//SysTick_Config(SystemCoreClock / 1000);
}


int main ()
{
    initHardware ();
    profilingInit ();

    struct profiling_t pr;
    testZeros (&pr);

	while (1)
	{
		__WFI();
	}
}
