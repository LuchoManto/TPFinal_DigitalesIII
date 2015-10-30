/*
 * serial.c
 *
 *  Created on: 30/10/2015
 *      Author: Luciano
 */

#include "headers.h"
#include "serial.h"

uint8_t caracter = 0;
uint8_t k = 0;
uint32_t IIR_temp;

void enviar (uint8_t c)
{
	while((LPC_UART3->LSR&(1<<5))==0){}
	LPC_UART3->THR=c;
}

void SysTick_Handler(void)
{
	static int i = 100;
	i--;
	if(i==0)
	{
		i=100;
		caracter++;
		enviar(caracter);
	}
}

/*interrupción que se genera por el módulo UART3
 * la única fuente de interrupción habilitada en el módulo UART3 es la de Receive data available*/

void UART3_IRQHandler(void)
{
	k=LPC_UART3->RBR;
	enviar(k);
}

void config_UART3(void)
{
	//Configuro UART
		LPC_SC -> PCONP |= (1<<25);				//Encendemos el periférico
		LPC_UART3 -> LCR |= 11;					//Configuramos la comunicación para que transmita tramas de 8 bits
		LPC_UART3 -> LCR |= (1<<7);
		LPC_UART3 -> DLL = 163; 				//DLL = 163 -> 9585 baudios -> error de 14 -> 0.1458%
		LPC_UART3 -> DLM = 0;
		LPC_UART3 -> LCR &=~ (1<<7);			//Colocamos el Bit DLAB nuevamente a cero
		LPC_UART3 -> IER = 1; 					//Corresponde a la interrupción por Receive Data Available
		NVIC_EnableIRQ(UART3_IRQn);
		LPC_PINCON -> PINSEL0 |= 0b1010; 		//Configuramos los pines P0[0] como TX y P0[1] como RX



}
