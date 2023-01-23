# scopetext
Display alpha/numeric debugging text on oscilloscope from PIC using single bit (analog DAC output)

This is a small .h file that renders text to the oscilloscope in normal sweep mode
using a single analog output put to generate the text. It's not pretty, but it is
functional for debugging firmware to display values (hex or decimal) in realtime.

Here's some oscilloscope screenshots:
![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/rigol-dots-mode.jpg)

Typical result on a digital scope.

![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/rigol-vector-mode.jpg)

Scope in vector mode is harder to read, but still visible.

![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/digits-vector-mode-closeup.jpg)

Closeup of the digits to see the "pixels", which are just small delays holding the analog output voltage.

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

The scope operates in normal "sweep" mode monitoring a single channel with a trigger.
Voltage and Time are adjusted to get the most readable results.
Since there are no special requirements for the scope, even old analog scopes can be used.

![screenshot](https://raw.githubusercontent.com/erco77/scopetext/main/images/analog-scope.jpg)

Analog scope.

For best results its important the DAC be responsive, fast during high speed changes.
Noise or slow ramps between changes can make the digits harder to read.

See README-scopetext.txt for more info on use and tweaking.
