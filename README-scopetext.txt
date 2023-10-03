README-scopetext.txt
====================

    USING SCOPETEXT
    ---------------
    Before using scopetext, verify your PIC chip's analog output using this simple test.
    Add in your main() loop this code (or something like it) to output a sawtooth wave:

         while ( 1 ) {                           // your main loop
              static unsigned char count = 0;    // loop counter
              DAC1CON1bits.DAC1R = count++;      // <-- change "DAC1CON1bits.DAC1R" to whatever
         }                                       //     your PIC's analog output variable is.

    Then build and burn the firmware to your PIC.
    On your scope's analog output pin, verify that you see:
           
                5v __
                        /|  /|  /|  /|  /|  /|  /|  /|  /|
                       / | / | / | / | / | / | / | / | / |
               Gnd __ /  |/  |/  |/  |/  |/  |/  |/  |/  |

    Once you have that working, use these steps to use scopetext in your program:

        1. Add the following to the top of your main() program:

              #include "scopetext.h"

           This must appear AFTER #include <xc.h>, so the file can access your PIC's
           variables.
           
        2. At the top of scopetest.h, under the "user configurable values", change the
           #define "SCOPETEXT_OUT" to be the name of your PIC chip's 8bit analog output port.
           For instance, with my PIC16F1709 the value would be:

               #define SCOPETEXT_OUT   DAC1CON1bits.DAC1R

           Different PIC chip models will have different requirements, so be sure to use
           the right values based on your sawtooth wave test (above).

           Note that some PIC chips don't have 8bit DACs (0-255), so you may need to 
           adjust the SCALE and YMAX values. 

	   For example: for a 5bit DAC (0-31), since the highest value is 31,
	   YMAX should be 31, e.g:


                    #define SCOPETEXT_YMAX      31

	   Normally YSCALE can be left at (SCOPETEXT_YMAX/6):

                    #define SCOPETEXT_YSCALE    (SCOPETEXT_YMAX/6)

	   If you adjust this value, be sure that (SCOPETEXT_YSCALE*(SCOPETEXT_HEIGHT-1))
	   is less than SCOPETEXT_YMAX, or the font will either wrap vertically, or
	   vertically truncated, or other ugly things.

           The font glyphs are 5 rows high, so the DAC values for drawing the font
	   will be:

	       SCOPETEXT_YMAX - (y*SCOPETEXT_YSCALE)

	   ..where y is in the range 0 to 4.

	   So the fonts will be flush to the top of the DAC's output, and will be
	   "drawn" below that voltage level based on the SCOPETEXT_YSCALE.

        3. As a test, somewhere in your main() loop, call:
        
                SCOPETEXT_Print("1234");

           ..to print the message (repeatedly).

        4. Build your app, and set your oscilloscope to monitor the analog output pin.
           Tweak the "Volts" and "Sweep Time" until the text is clear enough to see.
           Some scopes have special modes that improve the text visibility.
	   Feel free to also adjust the software values:

	       SCOPETEXT_YMAX          -- usually the highest value the DAC can handle
	       SCOPETEXT_YSCALE        -- usually (YMAX/6)
	       SCOPETEXT_PIXEL_WIDTH   -- in usecs

    SLOW DACS
    ---------
    Some Digital To Analog (DAC) devices are slow, in which case you may need to 
    add a small delay for each "pixel" in the font so it can be seen clearly above
    the DAC noise.

    In scopetext.h, look for the comment "add optional delay for wider pixels",
    and put a call to e.g. __delay_us() that's appropriate for your sweep rate.

    PROGRAMMING EXAMPLES
    --------------------
    See scopetext-examples/README.txt for info on how to print numeric values
    on the oscilloscope.

    You can use the C library string functions (such as itoa(), sprintf(), strcat()..),
    or you can use scopetext's built in "light weight" hex/dec conversion functions
    to display values without the need for any C library overhead.

    TO DISABLE SCOPETEXT
    --------------------
    If you no longer need scopetext in your program, comment out your
    #include "scopetext.h" line, and calls to any SCOPETEXT_xxx() functions.
