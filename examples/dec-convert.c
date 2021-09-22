//
// Demonstrate use of light-weight decimal conversion to print TMR values on oscilloscope.
//
#include "scopetext.h"

void MyShowDebugMessage() {
    unsigned char a = TMR0;         // For example, might be 38
    unsigned char b = TMR1;         // For example, might be 182
    char s[10];
    char *p = s;
    *p++ = 'a'; *p++ = '=';         // avoid strcat() for speed
    p = SCOPETEXT_AsDec(a, p);      // avoid itoa() for speed
    *p++ = ','; *p++ = 'b'; *p++ = '=';
    p = SCOPETEXT_AsDec(b, p);
    SCOPETEXT_Print(s);             // Prints "A=038,B=182" on scope
}
