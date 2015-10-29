/*
===============================================================================
 Name        : TP_Final.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#include "control_motor.h"
#endif

#include <cr_section_macros.h>


int main(void) {

	LPC_GPIO0->FIODIR |= (1<<22);
	LPC_GPIO0->FIOCLR |= (1<<22);

	config_PWM();

	LPC_GPIO0->FIOCLR |= (1<<22);

	/*
	while(1)
	{
		int i=0;
		for(i=10500; i<50000000; i=i+1000)
		{
			if(LPC_GPIO0->FIOPIN & (1<<22))
				LPC_GPIO0->FIOCLR |= (1<<22);
			else
				LPC_GPIO0->FIOSET |= (1<<22);

			arrancar_motor(i);

			int j=0;
			for(j; j<50000000; j++){}
		}
	}
	*/

	arrancar_motor(0);



	LPC_GPIO0->FIOSET |= (1<<22);


	while(1);

    return 0 ;
}
