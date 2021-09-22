# scopetext
Display alpha/numeric debugging text on oscilloscope from PIC using single bit (analog DAC output)

This is a small .h file that renders text to the oscilloscope in normal sweep mode
using a single analog output put to generate the text. It's not pretty, but it is
functional for debugging firmware to display values (hex or decimal) in realtime.

Here's some oscilloscope screenshots:
![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/rigol-dots-mode.jpg)
![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/rigol-vector-mode.jpg)
![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/analog-scope.jpg)
![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/digits-vector-mode-closeup.jpg)

Using the code is simple; just copy the one scopetext.h file into your firmware's
src directory, and add these two lines to your application:

    #include "scopetext.h"     // add this below your #include <xc.h>
    :
    SCOPETEXT_Print("abcd");	// add this in your main() where you want to print a value

The code is very light, and includes lightweight byte to hex and byte to unsigned decimal
conversion in the examples directory, avoiding the need for "heavy" C library functions
like `sprintf()` and `itoa()`.

When you're done debugging, you can just comment out (or #ifdef out) the above two lines,
making it easy to turn off for production.

