//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2012-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.0.1.11577 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

#define DELAY_VALUE        10000

void delay (void)
{
    for(int i=0;i<DELAY_VALUE;i++);
}

int main ( void )
{
SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock for PORTF
GPIO_PORTF_DEN_R  = 0x0E;  // Enable PORTF Pin1, 2 and 3 as a digital pins
GPIO_PORTF_DIR_R  = 0x0E;  // Configure ORTF Pin1, 2 and 3 digital output pins
		
	while (1) 
		{  
		GPIO_PORTF_DATA_R |= 0x02; // turn on red LED
        delay();
        GPIO_PORTF_DATA_R &= 0x00; // turn off red LED
		}
}
