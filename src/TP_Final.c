/*
===============================================================================
 Name        : TP_Final.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/



#include "headers.h"
#include "serial.h"
#include "conversor.h"
#include "control_motor.h"
#include "control_velocidad.h"


int main(void) {

	LPC_GPIO0->FIODIR |= (1<<22);
	LPC_GPIO0->FIOCLR |= (1<<22);

	config_UART3();
	//config_PWM();
	SysTick_Config(1000000);

	LPC_GPIO0->FIOCLR |= (1<<22);

	//arrancar_motor();



	LPC_GPIO0->FIOSET |= (1<<22);


	while(1);

    return 0 ;
}
