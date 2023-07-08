/*
 * Gpiod13_config.c
 *
 *  Created on: 9 Haz 2023
 *      Author: murat
 */

#include "Gpiod13_config.h"

void GpioConfig(void){
	RCC->AHB1ENR |= (1<<3);	//GPIO Bus enable


	  GPIOD->MODER |= (1<<26);	// General purpose output mode
	  GPIOD->MODER &= ~(1<<27);	// General purpose output mode

	  GPIOD->OTYPER &= ~(1<<13);	//Output push-pull

	  GPIOD->OSPEEDR &= ~(1<<27);
	  GPIOD->OSPEEDR |= (1<<26);

	  GPIOD->PUPDR = 0x00000000;
}

