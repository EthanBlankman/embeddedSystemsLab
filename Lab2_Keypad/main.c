// Ethan Blankman
// Embedded Systems Section 4?
// Keypad Reader
// Created: 31.1.24
// Last Updated: 31.1.24

/*
 * Rows:
 * - R1: P5.0
 * - R2: P5.1
 * - R3: P5.2
 * - R4: P5.3
 *
 * Cols:
 * - C1: P2.0
 * - C2: P2.1
 * - C3: P2.2
 * - C4: P2.4
 *
 * Keypad Indexing
 * Rows: Starting at the 1 key, Row0 -> Row3
 * Cols: Starting at the 1 key, Col0 -> Col3
 *
 * Example: B key is Row 1 Col 3
 *          7 key is Row 2 Col 0
 */


#include <msp430.h> 

// macro definitions
#define ROW1 BIT0
#define ROW2 BIT1
#define ROW3 BIT2
#define ROW4 BIT3

#define COL1 BIT0
#define COL2 BIT1
#define COL3 BIT2
#define COL4 BIT4

// Global Variable Declarations            define = find replace, global variable = value << general rule
const char rowMask = ROW1 + ROW2 + ROW3 + ROW4;    // const instead of define because the purpose is to use as code, not as a find/replace
const char rowMask = COL1 + COL2 + COL3 + COL4;
const char targetValue = 13;


// function declarations
char readRow();
char readCol();
char keyValue(char row, char col);  // Returns the char/value from the row/col pair
void checkValue(char val);      // Determines if
void gpioInit();


int main(void){
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	gpioInit();                 // Initialize LED and Keypad

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    char row = 0xFF; // 0xFF means no button pressed
    char col = 0xFF;
    char val = 0xFF;

	while(1){
	    row = readRow();          // Outputs row # zero indexed
	    col = readCol();            // Outputs col# zero indexed   - Top Left (1) is (0,0)
	    val = keyValue(row, col);
	    checkValue(val);
	}
	return 0;
}

void gpioInit(){
    // initialize LED
    P6DIR |= BIT6;     // Set P6.6 to output direction
    P6SEL0 &= ~BIT6;   // Change SEL0/1 Reg to GPIO
    P6SEL1 &= ~BIT6;

    // initialize keypad
    P2DIR |= colMask;  // Set Columns as outputs
    P2OUT |= colMask;  // Set Columns to 1

    P5DIR &= ~rowMask; // Set Rows as Inputs
    P5REN |= rowMask;  // Set Pins with Pulldown resistor
    P5OUT &= ~rowMask: //
}

char readRows(){
    // initialize Rows to inputs, Cols to outputs
    P2DIR |= colMask;  // Set Columns as outputs
    P2OUT |= colMask;  // Set Columns to 1

    P5DIR &= ~rowMask; // Set Rows as Inputs
    P5REN |= rowMask;  // Set Pins with Pulldown resistor
    P5OUT &= ~rowMask:

    char rowVal = P5IN & rowMask;

    switch(rowVal){
    case ROW1:
        return 0;
        break;
    case ROW2:
        return 1;
        break;
    case ROW3:
        return 2;
        break;
    case ROW4;
        return 2;
        break;
    default:
        return 0xFF;
        break;
    }
}

char readCols(){
    // initialize Col to inputs, Row to outputs
    P5DIR |= rowMask;  // Set Rows as outputs
    P5OUT |= rowMask;  // Set Rows to 1

    P2DIR &= ~colMask; // Set Col as Inputs
    P2REN |= colMask;  // Set Pins with Pulldown resistor
    P2OUT &= ~colMask:

    char colVal = P2IN & colMask;

    switch(colVal){
    case COL1:
        return 0;
        break;
    case COL2:
        return 1;
        break;
    case COL3:
        return 2;
        break;
    case COL4;
        return 2;
        break;
    default:
        return 0xFF;
        break;
}

char keyValue(char row, char col){
    char val = (row << 2) + col;       // reason why rows and cols are 0 indexed
    return (val > 15) ? 0xFF : val;    // return value of key or no key pressed if invalid
}

void checkValue(char val){
    // check val (keypad value) against target value and set LED based on result
    if(val == targetValue){
        P6OUT |= BIT6;  // Set LED
    } else {
        P6OUT &= ~BIT6; // Reset LED
    }
}
