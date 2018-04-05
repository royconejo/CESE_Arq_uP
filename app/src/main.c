#include "board.h"
#include "profiling.h"
#include "zeros.h"
#include "productoEscalar32.h"
#include "filtroVentana10.h"


static void initHardware ()
{
	Board_Init();
	SystemCoreClockUpdate();
	//SysTick_Config(SystemCoreClock / 1000);
}


int main ()
{
    initHardware    ();
    profilingInit   ();

    struct profiling_t pr;

    test_zeros              (&pr);
    test_productoEscalar32  (&pr);
    test_filtroVentana10    (&pr);

	while (1)
	{
		__WFI();
	}
}
