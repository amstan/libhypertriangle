//******************************************************************************
//  MSP430G2xx1 Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430G2xx1
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  D. Dang
//  Texas Instruments, Inc
//  October 2010
//  Built with CCS Version 4.2.0 and IAR Embedded Workbench Version: 5.10
//******************************************************************************

#include <msp430.h>
 
int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
	DCOCTL  = CALDCO_1MHZ;                    // Load the clock calibration
	BCSCTL1 = CALBC1_1MHZ;
	
	P1DIR |= 0x01;                            // Set P1.0 to output direction
	
	for (;;)
	{
		volatile unsigned int i;
		
		P1OUT ^= 0x01;                          // Toggle P1.0 using exclusive-OR
		
		i = 60000;                              // Delay
		do (i--);
		while (i != 0);
	}
}