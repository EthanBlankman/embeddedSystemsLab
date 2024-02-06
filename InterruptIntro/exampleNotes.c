#include <msp430.h>

/*
void LEDInit();
void buttonInit();

int main(void){
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    LEDInit();
    buttonInit();

    P4IES |= BIT1;   // Interrupt edge select <- sets the interupt to either a rising or falling edge
                     // 1 means Hi/Low edge, AKA High to Low edge, AKA falling edge
                     // Remember these buttons are default 1, so that is when the button is pressed
    P4IE |= BIT1;    // Interrupt enable for the pin (the *whole* pin, this isn't bit by bjt

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    P4IFG &= ~BIT1;  // Clear teh interrupt flag

    while(1){
    __bis_SR_register(LPM3_bit | GIE);  // enter lowpowermode3 with interrupt << stops code execution, among other thing
    __no_operation();                   // for debug
    P1OUT ^= BIT0;
    }
}

// Port 1 interrupt service routine        << if you want to debug interrupts put breakpoints in this service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt void Port_4(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT1_VECTOR))) Port_4 (void)
#else
#error Compiler not supported!
#endif
{
P4IFG &= ~BIT1; // Clear P1.3 IFG
__bic_SR_register_on_exit(LPM3_bits); // Exit LPM3
}




void LEDInit(){
    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction
}

void buttonInit(){
    P4DIR |= ~BIT1;                         // Set P4.1 (Button) to input direction
    P4OUT |= BIT1;                          // Configure P4.1 as pulled-up
    P4REN |= BIT1;                          // P4.1 pull-up register enable
} */
