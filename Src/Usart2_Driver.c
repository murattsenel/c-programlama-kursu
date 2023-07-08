/*
 * Usart2_Driver.c
 *
 *  Created on: Jun 9, 2023
 *      Author: murat
 */

#include <CB.h>
#include"stm32f4xx_hal.h"
#include"Usart2_Driver.h"


CircularBuffer *rxBuff;
CircularBuffer *txBuff;

uint8_t uartTxStatus = 0;
void Usart2_Config (CircularBuffer *rxB,CircularBuffer *txB)

{
	rxBuff = rxB;
	txBuff = txB;
RCC->APB1ENR |= (1<<17);
RCC->AHB1ENR |= (1<<0);

GPIOA->MODER |= (2<<4);  // alternate mode
GPIOA->MODER |= (2<<6);  // alternate mode

GPIOA->OSPEEDR |= (3<<4);  // high speed mode
GPIOA->OSPEEDR |= (3<<6);

GPIOA->AFR[0] |= (7<<8);   // af7 alternate mode usart2 pa2 pin
GPIOA->AFR[0] |= (7<<12);  //                           pa3

// ENABLE USART2

USART2->CR1= 0x00 ;  // clear all

USART2->CR1 |= (1<<13);  // ue enable

USART2->CR1 &= ~(1<<12); // m00 8 bit legth

//// baudrate

USART2->BRR |= (1<<0);
USART2->BRR |= (13<<4);

 // enable receiver , transmitter

USART2->CR1 |= (1<<2);
USART2->CR1 |= (1<<3);

SET_BIT(USART2->CR1, USART_CR1_RXNEIE);

HAL_NVIC_SetPriority(USART2_IRQn, 0, 1);
HAL_NVIC_EnableIRQ(USART2_IRQn);

}

void USART2_IRQHandler(void)
{


  /* UART in mode Receiver */
  if(((((1<<5) & USART2->SR)!=0) && ((1<<5) & USART2->CR1) != 0))
  {

      writeCircularBuffer( rxBuff, USART2->DR);

  }
  if((((1<<7) & USART2->SR) != 0) && (((1<<7) & USART2->CR1) != 0))
    {

                                             //if txBuffer not empty
	  if( 0 == isCircularBufferEmpty(txBuff)){
	   readCircularBuffer( txBuff, &USART2->DR);
	  //then send
	  }
	  else
	  {
  			CLEAR_BIT(USART2->CR1, USART_CR1_TXEIE);
  			uartTxStatus = 0;
	  }

    }
}


void WriteChar (uint8_t c)
{
	while(!(USART2->SR & (1<<7)));
	USART2->DR =(uint32_t) c;



}
uint32_t ReadChar (void)
{
	while(!(USART2->SR & (1<<5)));

     return USART2->DR;


}

void sendArray( char * data, uint32_t length )
{
	while(length--)
	{
		writeCircularBuffer( txBuff, *data++);
	}

	if( uartTxStatus == 0 )
	{
		SET_BIT(USART2->CR1, USART_CR1_TXEIE);
		uartTxStatus = 1;
	}
}

void WriteStr (char *string)
{
	while(*string){
		WriteChar(*string++);

		if(*string=='\0')
		   break ;

	}

}
void ReadStr (char * p)
{
      char c;

	  while( (c=ReadChar())!='\n' )
		 *p++ = (char) c;

		 *p = '\0';

}











