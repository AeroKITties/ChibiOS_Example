#include "print_lib.h"

// Some functions for printing ower SWO (debug only)
void SWO_PrintChar(char const c, uint8_t const portNo)
{
    volatile int timeout;

    /* Check if Trace Control Register (ITM->TCR at 0xE0000E80) is set */
    /* check Trace Control Register if ITM trace is enabled*/
    if ((ITM->TCR & ITM_TCR_ITMENA_Msk) == 0)
    {
        return; /* not enabled? */
    }
    /* Check if the requested channel stimulus port (ITM->TER at 0xE0000E00) is enabled */
    /* check Trace Enable Register if requested port is enabled */
    if ((ITM->TER & (1ul << portNo)) == 0)
    {
        return; /* requested port not enabled? */
    }
    timeout = 5000; /* arbitrary timeout value */
    while (ITM->PORT[0].u32 == 0)
    {
        /* Wait until STIMx is ready, then send data */
        if (--timeout == 0)
        {
            return; /* not able to send */
        }
    }
    ITM->PORT[0].u8 = (uint8_t)c;
}
void SWO_PrintString(char const* s, uint8_t const portNumber)
{
    while (*s != '\0')
    {
        SWO_PrintChar(*s++, portNumber);
    }
}
void printString(char const* str)
{
    SWO_PrintString(str, 0);
}

