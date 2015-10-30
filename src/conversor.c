/*
 * conversor.c
 *
 *  Created on: 22/10/2015
 *      Author: Luciano
 */

#include "headers.h"

void config_adc()
{
	LPC_SC->PCONP |= (1 << 12); // habilitar el periferico PCONP para que funcione el ADC, por defecto esta deshabilitado

	LPC_SC->PCLKSEL0 &= ~(1 << 24);
	LPC_SC->PCLKSEL0 &= ~(1 << 25); // selecciono clock de adc en sysclock / 4

	LPC_ADC->ADCR |= (1 << 21); // coloca el ADC en modo operacional

	LPC_ADC->ADCR |= (1 << 8); // coloco el divisor de clock del adc en 1 para que se divida 25 / 2 y de 12,5 que es < 13

	LPC_PINCON->PINSEL0 |= (1 << 14);
	LPC_PINCON->PINSEL0 &= ~(1 << 15); //bits 14 y 15 de pinsel0 en "01" hacen que P0.23 sea AD0.0

	LPC_PINCON->PINMODE1 |= (1 << 15); //configuro el pin de entrada de modo que no tenga ni pull down ni pull up

	LPC_ADC->ADCR |= (1 << 16); //habilita el bit de interrupcion del ADC
	LPC_ADC->ADCR->START |= (1 << 26); //comenzar conversion cuando hay flanco en MATCH 1 de Timer0
	LPC_ADC->ADCR->START &= ~(1 << 27); //flanco de subida activa la conversion

}


void ADC_IRQHandler()
{
	int valor_convertido;
	float valor_real;

	LPC_ADC->ADSTAT &= ~ (1<<16); // se baja la bandera de interrupcion del adc
	if(LPC_ADC->ADSTAT & 1)
		LPC_ADC->ADSTAT &= ~ 1; // si la bandera que se subio era la del canal 0, se baja el bit de DONE correspondiente

	valor_convertido = (int)LPC_ADC->ADDR0;

	// valor real == (Vref+ - Vref-) * valor convertido /(2^resolucion - 1)
	// valor real == 2*valor convertido / 4095

	valor_real = (2*valor_convertido) / 4095;

	//tabla de division para los leds
/*
	valor_real == 0     			=>     0 leds prendidos
	0 < valor_real < 0,25 			=>	   1 leds prendidos
	0,25 < valor_real < 0,5 		=>	   2 leds prendidos
	0,5 < valor_real < 0,75 		=>	   3 leds prendidos
	0,75 < valor_real < 1 			=>	   4 leds prendidos
	1 < valor_real < 1,25 			=>	   5 leds prendidos
	1,25 < valor_real < 1,50 		=>	   6 leds prendidos
	1,50 < valor_real < 1,75 		=>	   7 leds prendidos
	1,75 < valor_real < 2 			=>	   8 leds prendidos
*/
	if(valor_real == 0)
		LPC_GPIO->FIOPIN |= 0x00;
	else if(0 < valor_real < 0.25)
		LPC_GPIO->FIOPIN |= 0x01;
	else if(0.25 < valor_real < 0.5)
		LPC_GPIO->FIOPIN |= 0x03;
	else if(0.5 < valor_real < 0.75)
		LPC_GPIO->FIOPIN |= 0x07;
	else if(0.75 < valor_real < 1)
		LPC_GPIO->FIOPIN |= 0x0F;
	else if(1 < valor_real < 1.25)
		LPC_GPIO->FIOPIN |= 0x1F;
	else if(1.25 < valor_real < 1.5)
		LPC_GPIO->FIOPIN |= 0x3F;
	else if(1.5 < valor_real < 1.75)
		LPC_GPIO->FIOPIN |= 0x7F;
	else if(1.75 < valor_real < 2)
		LPC_GPIO->FIOPIN |= 0xFF;

}
