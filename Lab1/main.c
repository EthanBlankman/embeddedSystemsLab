#include <msp430.h> 


/**
 * main.c
 */
/*
 * RGB LED Test Code
 * This code cycles between combinations of RGB colors to test RGB LEDS and they stylings
 *
 * This code is designed for a common anode RGB LED
 *
 * Pins utilized:
 * - P6.0 - Red
 * - P6.1 - Green
 * - P6.2 - Blue
 *
 * Author: Ethan Blankman
 * Last Rev: 1/24/24
 *
 */



#include <msp430.h>

#define speed 150000

int main(void){
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P6DIR |= BIT0 + BIT1 + BIT2; // set pin 1.2, 1.3, and 1.5 (RED, GREEN, BLUE) as Output

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings

    // Initial Output (RED)
    P6OUT |= BIT1+BIT2;   // set Green and Blue off
    P6OUT &= ~BIT0;       // set Red on

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1) {
        P6OUT++;
        __delay_cycle(speed);
    }
}
