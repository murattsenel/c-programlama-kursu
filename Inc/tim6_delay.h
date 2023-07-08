/*
 * tim6_delay.h
 *
 *  Created on: 9 Haz 2023
 *      Author: murat
 */

#ifndef INC_TIM6_DELAY_H_
#define INC_TIM6_DELAY_H_

#include"stm32f4xx_hal.h"

void TIM6Config (void);
void Delay_us (uint16_t us);
void Delay_ms(uint16_t ms);


#endif /* INC_TIM6_DELAY_H_ */
