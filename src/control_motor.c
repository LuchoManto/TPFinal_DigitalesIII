/*
 * control_motor.c
 *
 *  Created on: 22/10/2015
 *      Author: Luciano
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#include "control_motor.h"
#endif

#include <cr_section_macros.h>

void config_PWM(void)
{
	LPC_GPIO2->FIODIR |= (1 << 0);

	LPC_SC->PCLKSEL0 &= ~(1 << 13);
	LPC_SC->PCLKSEL0 &= ~(1 << 12); // clock del PWM = SYSCLK / 4 = 25 MHz

	LPC_PINCON->PINSEL4 |= (1 << 0); // pinsel configurado para que P2.0 sea la salida de la señal del PWM

	LPC_PWM1->MR0 = 65789; // Valor del periodo del PWM para que el periodo del PWM sea 380 Hz
	LPC_PWM1->MR1 = 10000; // Valor del ciclo de trabajo del PWM. inicial en 0
	LPC_PWM1->LER |= (1 << 1); // actualizo latch de match1
	LPC_PWM1->LER |= (1 << 0); // actualizo latch de match0

	LPC_PWM1->MCR |= (1 << 4); // reset en MR1

	LPC_PWM1->PCR |= (1 << 9); // PWM1 output enable

	LPC_PWM1->TCR |= (1 << 0); // habilitar el timer
	LPC_PWM1->TCR |= (1 << 3); // poner el timer en modo PWM


}

void arrancar_motor(void)
{
	set_Pwm(42200);
	delay(25000000);
	set_Pwm(42100);
	delay(25000000);
	set_Pwm(33264);
	delay(25000000);
	set_Pwm(36000);
}

void set_Pwm(unsigned int num)
{
	LPC_PWM1->MR1 = num; // Valor del ciclo de trabajo del PWM.
	LPC_PWM1->LER |= (1 << 1); // actualizo latch de match1
}

void delay(unsigned int num)
{
	int i;
	for(i = num; i > 0; i--);
}
