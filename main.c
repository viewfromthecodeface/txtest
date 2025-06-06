#include <xc.h>

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3 as I/O)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection off)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory not protected)

#define _XTAL_FREQ 4000000  // Define the oscillator frequency for delay routines

void main(void) {
    // Configure GP2 as output
    TRISIO2 = 0;     // GP2 = output
    GPIO = 0x00;     // Clear output pins
    ANSEL = 0x00;    // All pins digital
    CMCON = 0x07;    // Disable comparators

    while (1) {
        GP2 = 1;                     // Set GP2 high
        __delay_us(1875);           // ON for 1875 µs (75%)

        GP2 = 0;                     // Set GP2 low
        __delay_us(625);            // OFF for 625 µs (25%)
    }
}
