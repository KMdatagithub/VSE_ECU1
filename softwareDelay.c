/*
 * softwareDelay.c
 *
 * Created: 1/18/2020 2:48:30 PM
 *  Author: A_ayman
 */ 
#include "softwareDelay.h"

void SwDelay_ms(uint32_t n)
{
	/*/ this function will give you a delay of 1 ms if your frequency is 8 MHZ  */
	/*	                                   of 2 ms if your frequency is 4 MHZ    */
	/*  for each n delay it will give you n ms */
   /* the value of internal_iteration_NO may be less than or greater than the value i choose */
	/* because of the context switching between functions and how much time does it take. */
	/*
	/*/
	volatile uint32_t z=0;
   uint16_t j=0;
	uint32_t i=0;
	
	for(i=0; i<n;i++)
	{
		for( j=0; j<internal_iteration_NO;j++) //the number of internal iteration related to the kindd of the command and how many cycles does it take.
		{
			z++; //it can be any instruction Just for not making the compiler ignore the loop.
			
		}	
	}
}
