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

	config_PWM();
	arrancar_motor();

	while(1);

    return 0 ;
}
