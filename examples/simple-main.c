// Example simple-main.c showing how to use SCOPETEXT_Print().

// Includes the configured PIC
#include <xc.h>

// If you're using MCC (Microchip Code Configurator) to configure
// your pic chip (which should include the #define for _XTAL_FREQ),
// then you'd include that code here, e.g.
//
// #include "mcc_generated_files/mcc.h"

#include "scopetext.h"    // should be after '#include <xc.h>' and any MCC .h files

void main(void)
{
    SYSTEM_Initialize();                      // initialize your PIC chip
    while (1) {
        SCOPETEXT_Print("0123456789abcdef");  // test message
        __delay_ms(20);                       // time between repeating messages
    }
}
