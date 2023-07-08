/*
 * tim6_delay.c
 *
 *  Created on: 9 Haz 2023
 *      Author: murat
 */



#include"tim6_delay.h"

void TIM6Config (void){
	RCC->APB1ENR |= (1<<4); // enable the timer6 clock

	TIM6->PSC = 48-1; // 16mhz/16 = 1mhz

	TIM6->ARR = 0xffff ; // max arr value

	TIM6->CR1 |=(1<<0) ; // enable the counter

	while(!(TIM6->SR & (1<<0)));

}

void Delay_us (uint16_t us){

	TIM6->CNT = 0;
    while(TIM6->CNT < us);
}

void Delay_ms(uint16_t ms){

	for(uint16_t i=0 ; i<ms ; i++){
		Delay_us(1000);
	}
}
