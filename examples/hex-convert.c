//
// Demonstrate use of light-weight hex conversion to print TMR values on oscilloscope.
//
#include "scopetext.h"

void MyShowDebugMessage() {
    unsigned char a = TMR0;         // For example, might be 0x55
    unsigned char b = TMR1;         // For example, might be 0x1F
    char s[10];
    char *p = s;
    *p++ = 'a'; *p++ = '=';         // avoid strcat() for speed
    p = SCOPETEXT_AsHex(a, p);      // avoid itoa() for speed
    *p++ = ','; *p++ = 'b'; *p++ = '=';
    p = SCOPETEXT_AsHex(b, p);
    SCOPETEXT_Print(s);             // Prints "A=55,B=1F" on scope
}
