// Ethan Blankman
// 2.1.24
// Blink the Red and Green LEDs depending on if their respective buttons are pressed
// Red LED      = P1.0
// Red Button   = P4.1
// Green LED    = P6.6
// Green Button = P2.3

#include <msp430.h>

#define redPin P1OUT
#define redBit BIT0
#define redButton P4IN

#define greenPin P6OUT
#define greenBit BIT6
#define greenButton P2IN

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P2DIR |= ~BIT3;                         // Set P2.3 (Button) to input direction
    P2OUT |= BIT3;                          // Configure P2.3 as pulled-up
    P2REN |= BIT3;                          // P2.3 pull-up register enable

    P4DIR |= ~BIT1;                         // P4.1 Button Configuration
    P4OUT |= BIT1;
    P4REN |= BIT1;

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P6OUT &= ~BIT6;                         // P6.6 Configuration
    P6DIR |= BIT6;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1) {

        // Turn on LED if button pressed
        redPin |= ((~redButton) >> 1) & redBit;
        greenPin |= ((~greenButton) << 3) & greenBit;
            // Shifts button bit to same location as LED and uses a mask to isolate the bit wanted
            // Button is inverted to make it correspond to LED (0 = off, 1 = on)

        __delay_cycles(500000);

        // Always turn off LED
        P1OUT &= ~BIT0;
        P6OUT &= ~BIT6;
        __delay_cycles(500000);
    }
}
